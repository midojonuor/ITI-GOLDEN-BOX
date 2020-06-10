import GoldenBox 
import GoldenBox_prephiral 





GB = GoldenBox.client("localhost",800)

DO = GoldenBox.Digital_output(GB)

DI = GoldenBox.Digital_input(GB)


DO.Case(GoldenBox_prephiral.Digital_Output[GoldenBox_prephiral.CH_01],GoldenBox_prephiral.LOW)

DI.Assert(GoldenBox_prephiral.Digital_Input[GoldenBox_prephiral.CH_01],GoldenBox_prephiral.LOW)








