#include "stdio.h"

#include "stdlib.h"
#include "stdint.h"
#include "FDX.h"


uint8_t buffer[1024];

int 
main(int argc, char **argv)
{
	FDX_Header_t *pFDX_Header = (FDX_Header_t *) buffer;
	FDX_Start_t *pFDX_Start = (FDX_Start_t *)&buffer[CMD_SIZE_OFFSET];
	FDX_Stop_t *pFDX_Stop = (FDX_Stop_t *)&buffer[CMD_SIZE_OFFSET];
	FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *)&buffer[CMD_SIZE_OFFSET];
	FDX_Status_t *pFDX_Status = (FDX_Status_t *)&buffer[CMD_SIZE_OFFSET];

	FDX_CreateFrameHeader(buffer, 6);
	printf("----------------------Header Test-------------------------\n");
	printf("Signature: 0x%llX\n", pFDX_Header->Signeture);
	printf("Major Version: %d\n", pFDX_Header->MajorVersion);
	printf("Minor Version: %d\n", pFDX_Header->MinorVersion);
	printf("Number of command: %d\n", pFDX_Header->NumOfCMD);
	printf("Sequence number: %d\n", pFDX_Header->SeqNum);


	FDX_CreateStartCmd(buffer);
	printf("----------------------Start Command test-------------------------\n");
	printf("Command Size: %d\n", pFDX_Start->CommandSize);
	printf("Command Code: %d\n", pFDX_Start->CommandCode);


	FDX_CreateStopCmd(buffer);
	printf("----------------------Stop Command test-------------------------\n");
	printf("Command Size: %d\n", pFDX_Stop->CommandSize);
	printf("Command Code: %d\n", pFDX_Stop->CommandCode);

	FDX_CreateDataExchangeCmd(buffer, PERIPH_ID_DIGITAL_INPUT,10, &buffer[DATAEX_BYTES_OFFSET]);
	printf("----------------------Data Exchange Command test-------------------------\n");
	printf("Command Size: %d\n", pFDX_DataExchange->CommandSize);
	printf("Command Code: %d\n", pFDX_DataExchange->CommandCode);
	printf("Group ID: %d\n", pFDX_DataExchange->GroupID);
	printf("Data Size: %d\n", pFDX_DataExchange->DataSize);
	printf("Data Bytes: %d\n", pFDX_DataExchange->DataBytes);


	FDX_CreateStatusCmd(buffer, SESSION_OPENED, 1000);
	printf("----------------------Status Command test-------------------------\n");
	printf("Command Size: %d\n", pFDX_Status->CommandSize);
	printf("Command Code: %d\n", pFDX_Status->CommandCode);
	printf("Status: %d\n", pFDX_Status->Status);
	printf("Time Stamp: %d\n", pFDX_Status->TimeStamp);



	return 0;
}
