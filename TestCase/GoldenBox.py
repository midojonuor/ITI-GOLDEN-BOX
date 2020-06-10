import sys
import xmlrpc.client

from XMLRPCserver import *



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
    if ( value == self.GBclient.DIO_CH_GET(channel_number) ):
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
    if ( value == self.GBclient.DIO_CH_GET(channel_number) ):
      print("This Test case passed successufuly")
    else : 
      print("This Test Case Failed")
        

  


  



