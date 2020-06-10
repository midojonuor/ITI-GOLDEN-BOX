import sys
import xmlrpc.client

#from XMLRPCserver import *

HIGH = 1
LOW = 0

CH_01 = 0
CH_02 = 1
CH_03 = 2
CH_04 = 3
CH_05 = 4
CH_06 = 5
CH_07 = 6
CH_08 = 7


class client:
  GBclient = 0
  def __init__(self, ip , port):      
    self.GBclient = xmlrpc.client.ServerProxy("http://%s:%s" %(ip, port))
    print("The client is running.... ") 
 

   
class Digital_input:
  GBclient = 0
  def __init__(self, golden ):
    self.GBclient = golden.GBclient
    

        
  def Assert(self, channel_number, value): 
    ActualValue = self.GBclient.DI_CH_GET(channel_number)
    print(ActualValue)
    if ( ActualValue == value ):
      print("This Test case passed successufuly")
    else : 
      print("This Test Case Failed")
    
 


class Digital_output:
  GBclient = 0
  def __init__(self, golden ):
    self.GBclient = golden.GBclient
    
  def Case(self, channel_number, channel_state):
    if ( channel_state == 1) :
      self.GBclient.DO_CH_SET(channel_number)
      print(" passed successufuly and set this channel")
    else :
      self.GBclient.DO_CH_RESET(channel_number)
      print(" passed successufuly and rest this channel")
    
    
  def Assert(self, channel_number, value): 
    if ( value == self.GBclient.DO_CH_GET(channel_number) ):
      print("This Test case passed successufuly")
    else : 
      print("This Test Case Failed")
        

  


  



