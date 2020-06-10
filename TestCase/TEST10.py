import GoldenBox 

GB = GoldenBox.client("192.168.1.55",5000)

#print(GB.GBclient.system.listMethods())

DO = GoldenBox.Digital_output(GB)

DI = GoldenBox.Digital_input(GB)

DO.Case(GoldenBox.CH_01,GoldenBox.HIGH)

DI.Assert(GoldenBox.CH_01,GoldenBox.HIGH)








