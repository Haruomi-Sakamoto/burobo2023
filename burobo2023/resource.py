class Settings:
    def __init__(self):
        self.serialport = 'COM11'
        self.comspeed = 9600
        self.vaudlim = 0.1

class Constants:
    def __init__(self):
        self.BUTTON_DEFALT = '0'
        self.NEUTRAL = '127'
        self.MAPCENTER = 127.5
        self.STICK_THRESHOLD = 0.1
        
        self.PS       = '1'
        self.OPTIONS  = '2'
        self.SHARE    = '3'
        self.TOUCHPAD = '4'
        self.TRIANGLE = '5'
        self.SQUARE   = '6'
        self.CROSS    = '7'
        self.CIRCLE   = '8'
        self.UP       = '9'
        self.LEFT     = '10'
        self.DOWN     = '11'
        self.RIGHT    = '12'
        self.L1       = '13'
        self.R1       = '14'
        self.L3       = '15'
        self.R3       = '16'

settings = Settings()
constants = Constants()