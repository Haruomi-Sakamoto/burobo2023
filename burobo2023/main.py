import pygame
import serial

from resource import settings
from resource import constants

class PS4Controller:
    def __init__(self):
        pygame.init()
        self.ps4 = pygame.joystick.Joystick(0)
        self.ps4.init()
        self.serial_port = serial.Serial(settings.serialport, settings.comspeed, timeout=settings.vaudlim)
        self.button_status = constants.BUTTON_DEFALT
        self.lx = self.ly = self.rx = self.ry = constants.NEUTRAL
        self.result = []
        
    def mapping(self, value):
        return int((value + 1) * constants.MAPCENTER)

    def read_dualshock(self):
        events = pygame.event.get()
        for event in events:
            if event.type == pygame.JOYBUTTONDOWN:
                if self.ps4.get_button(0):
                    self.button_status = constants.CROSS
                elif self.ps4.get_button(1):
                    self.button_status = constants.CIRCLE
                elif self.ps4.get_button(2):
                    self.button_status = constants.SQUARE
                elif self.ps4.get_button(3):
                    self.button_status = constants.TRIANGLE
                elif self.ps4.get_button(4):
                    self.button_status = constants.SHARE
                elif self.ps4.get_button(5):
                    self.button_status = constants.PS
                elif self.ps4.get_button(6):
                    self.button_status = constants.OPTIONS
                elif self.ps4.get_button(7):
                    self.button_status = constants.L3
                elif self.ps4.get_button(8):
                    self.button_status = constants.R3
                elif self.ps4.get_button(9):
                    self.result = constants.L1
                elif self.ps4.get_button(10):
                    self.button_status = constants.R1
                elif self.ps4.get_button(11):
                    self.button_status = constants.UP
                elif self.ps4.get_button(12):
                    self.button_status = constants.DOWN
                elif self.ps4.get_button(13):
                    self.button_status = constants.LEFT
                elif self.ps4.get_button(14):
                    self.button_status = constants.RIGHT
                elif self.ps4.get_button(15):
                    self.button_status = constants.TOUCHPAD
                    
            elif event.type == pygame.JOYBUTTONUP:
                self.button_status = constants.BUTTON_DEFALT
                
            elif event.type == pygame.JOYAXISMOTION:
                if abs(self.ps4.get_axis(0)) >= constants.STICK_THRESHOLD or abs(self.ps4.get_axis(1)) >= constants.STICK_THRESHOLD:
                    self.lx = self.mapping(round(self.ps4.get_axis(0), 3))
                    self.ly = self.mapping(round(self.ps4.get_axis(1), 3)*-1)
                else:
                    self.lx = self.ly = constants.NEUTRAL
                if abs(self.ps4.get_axis(2)) >= constants.STICK_THRESHOLD or abs(self.ps4.get_axis(3)) >= constants.STICK_THRESHOLD:
                    self.rx = self.mapping(round(self.ps4.get_axis(2), 3))
                    self.ry = self.mapping(round(self.ps4.get_axis(3), 3)*-1)
                else:
                    self.rx = self.ry = constants.NEUTRAL
                    
        self.result = [self.button_status, self.lx, self.ly, self.rx, self.ry,0]
        #print(self.result)
        print("{:<3}".format(self.button_status),"{:<5}".format(self.lx),"{:<5}".format(self.ly), 
              "{:<5}".format(self.rx), "{:<5}".format(self.ry))
        
    def write_to_arduino(self):
        data_to_send = ",".join(map(str, self.result))
        self.serial_port.write(data_to_send.encode())
        #print(data_to_send.encode())

if __name__ == '__main__':
    main = PS4Controller()
    
    while True:
        main.read_dualshock()
        main.write_to_arduino()