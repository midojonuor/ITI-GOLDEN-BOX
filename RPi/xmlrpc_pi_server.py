from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

#import RPi.GPIO as GPIO

import time

#GPIO.setmode(GPIO.BCM)

DI_CH_00 = 17
DI_CH_01 = 27
DI_CH_02 = 22
DI_CH_03 = 5
DI_CH_04 = 6
DI_CH_05 = 13
DI_CH_06 = 19
DI_CH_07 = 26
DO_CH_08 = 18
DO_CH_09 = 23
DO_CH_10 = 24
DO_CH_11 = 25
DO_CH_12 = 12
DO_CH_13 = 16
DO_CH_14 = 20
DO_CH_15 = 21


GoldenBox_DIO = [
    DI_CH_00,
    DI_CH_01,
    DI_CH_02,
    DI_CH_03,
    DI_CH_04,
    DI_CH_05,
    DI_CH_06,
    DI_CH_07,
    DO_CH_08,
    DO_CH_09,
    DO_CH_10,
    DO_CH_11,
    DO_CH_12,
    DO_CH_13,
    DO_CH_14,
    DO_CH_15
]


class RequestHandler(SimpleXMLRPCRequestHandler):
	rpc_paths = ('/RPC2')


def GoldenBox_Init():
    """    for i in range(8):
        GPIO.setup(GoldenBox_DIO[i], GPIO.IN)
        GPIO.setup(GoldenBox_DIO[8 + i], GPIO.OUT)
    """

def DO_CH_Write(CH_Num, Status):
    """
	GPIO.output(GoldenBox_DIO[CH_Num], Status)
	return Status
    """
    print("DO_CH Function call")
    return 0
def DI_CH_Read(CH_Num):
    """
    return GPIO.input(GoldenBox_DIO[CH_Num])
    """
    print("DI_CH Function call")
    return 0



if __name__ == "__main__":

    server = SimpleXMLRPCServer(("192.168.1.3", 8080), requestHandler=RequestHandler)
    server.register_introspection_functions()
    server.register_function(DO_CH_Write)
    server.register_function(DI_CH_Read)
    
  #  GoldenBox_Init()

    print("Server up and listening...")
    server.serve_forever()
