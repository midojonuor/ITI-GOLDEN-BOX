/*
 * FdxUdpServer.c
 *
 *  Created on: Jun 5, 2020
 *      Author: midoj
 */

/* standard libraries */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

/* UDP libraries */
#include "unistd.h"
#include "string.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "sys/time.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "netdb.h"


/* fdx and udp header files */
#include "udp.h"
#include "FDX.h"
#include "FDX_Server.h"



#define TOTAL_DIGITAL_INPUT_CHANNEL					8
#define TOTAL_DIGITAL_OUTPUT_CHANNEL				8

#define SEQ_NUM_INDX_START							0
#define SEQ_NUM_INDX_STOP							1
#define SEQ_NUM_INDX_DATA_EXCHANGE					2
#define SEQ_NUM_INDX_STATUS							3

static UDP_Server server;
static uint16_t Session_Status = 0;

/*
 * Sequence number array elements:
 * 		1. Cmd_Start
 * 		2. Cmd_Stop
 *
 */
static uint16_t Sequance_Number[4];


static Std_ReturnType DataExchange_Handler(uint16_t groupId, Server_Config_t *server)
{
	Std_ReturnType ApiStatus = E_OK;
	uint16_t periph_id = 0;
	uint16_t indx = 0;

	FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *) &server->recv_msg[CMD_SIZE_OFFSET];

	if(Session_Status == SESSION_OPEN)
	{
#if DEBUG_START
		printf("Session status check passed\n");
		fflush(stdout);
#endif

		if(GET_DIR(groupId) == DIR_APP_TO_GOLDENBOX)
		{
#if DEBUG_START
			printf("Direction check passed\n");
			fflush(stdout);
#endif
			periph_id = GET_PERIPH_ID(groupId);

			switch(periph_id)
			{

			case PERIPH_ID_DIGITAL_INPUT:

#if DEBUG_START
				printf("Digital Peripheral ID check passed\n");
				fflush(stdout);
#endif

				/* Data size must  be even number (2 bytes for each channel "channel number, Status" ) */
				for(indx = 0; indx < pFDX_DataExchange->DataSize; indx += 2)
				{
					if(server->recv_msg[DATAEX_BYTES_OFFSET + indx] >= TOTAL_DIGITAL_INPUT_CHANNEL)
					{
						ApiStatus = E_NOT_OK;
						break;
					}

					server->sent_msg[DATAEX_BYTES_OFFSET + indx] = server->recv_msg[DATAEX_BYTES_OFFSET + indx];

					//					DigitalRead(server->sent_msg[DATAEX_SIZE_OFFSET + indx],
					//							&server->sent_msg[DATAEX_SIZE_OFFSET + indx + 1]);
				}



				if(ApiStatus == E_OK)
				{
					/* Create header frame with incremental sequence number */
					FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
					Sequance_Number[SEQ_NUM_INDX_DATA_EXCHANGE] += 1;

					/* Assign data to be sent */
					FDX_CreateDataExchangeCmd(server->sent_msg,
							(DIR_GOLDENBOX_TO_APP | PERIPH_ID_DIGITAL_INPUT),
							pFDX_DataExchange->DataSize,
							&server->sent_msg[DATAEX_BYTES_OFFSET]);
					server->total_bytes_to_send = HEADER_SIZE + CMD_DATA_EXCHANGE_SIZE + pFDX_DataExchange->DataSize;
				}
				else
				{
					/* Create header frame with incremental sequence number */
					FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
					Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;


					/* Create status command */
					FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_NOK), 0);
					server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;
				}

				break;


			case PERIPH_ID_DIGITAL_OUTPUT:

#if DEBUG_START
				printf("Digital output Peripheral ID check passed\n");
				fflush(stdout);
#endif
				/* Apply Changes to HW */
				for(indx = 0; indx < pFDX_DataExchange->DataSize; indx += 2)
				{

#if DEBUG_START
					printf("Channel number: %d\n", server->recv_msg[DATAEX_BYTES_OFFSET + indx]);
					fflush(stdout);
#endif
					if(server->recv_msg[DATAEX_BYTES_OFFSET + indx] >= TOTAL_DIGITAL_OUTPUT_CHANNEL)
					{
						ApiStatus = E_NOT_OK;
						break;
					}
					server->sent_msg[DATAEX_SIZE_OFFSET + indx] = server->recv_msg[DATAEX_BYTES_OFFSET + indx];

					//					DigitalWrite(server->sent_msg[DATAEX_SIZE_OFFSET + indx],
					//							server->sent_msg[DATAEX_SIZE_OFFSET + indx + 1]);
				}


				/* Create header frame with incremental sequence number */
				FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
				Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;


				if(ApiStatus == E_OK)
				{
					/* Create status command */
					FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_OK), 0);
					server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;
				}
				else
				{
					/* Create status command */
					FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_NOK), 0);
					server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;
				}
				break;

			default:
				ApiStatus = E_NOT_OK;

				/* Create header frame with incremental sequence number */
				FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
				Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

				/* Create status command */
				FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_NOK), 0);
				server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;
				break;
			}
		}
		else
		{
			ApiStatus = E_NOT_OK;
			/* Create header frame with incremental sequence number */
			FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
			Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

			/* Create status command */
			FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_NOK), 0);
			server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;
		}
	}
	else
	{
		/* Create header frame with incremental sequence number */
		FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
		Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

		/* Create status command */
		FDX_CreateStatusCmd(server->sent_msg, (SESSION_CLOSE | RESPOND_NOK), 0);
		server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;

#if DEBUG_START
		printf("No session opened\n");
		fflush(stdout);
#endif
	}

	return ApiStatus;
}


static void FdxServer_Handler(Server_Config_t *server)
{
	Std_ReturnType result = E_NOT_OK;

	uint16_t frameType = 0;
	uint16_t dataSize = 0;
	uint16_t groupID = 0;


	result = FDX_ParsingFrame(server->recv_msg, &frameType, &dataSize, &groupID);

	if(result == E_OK)
	{
		switch(frameType)
		{
		case Cmd_Start:
			Session_Status = SESSION_OPEN;
			memset(Sequance_Number, 0, (sizeof(uint16_t) * 4));
			/* Create header frame with incremental sequence number */
			FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
			Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

			/* Create status command */
			FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_OK), 0);
			server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;

#if DEBUG_START
			printf("OK...............Start command received\n");
			fflush(stdout);
#endif
			break;

		case Cmd_Stop:
			Session_Status = SESSION_CLOSE;
			/* Create header frame with incremental sequence number */
			FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
			Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

			/* Create status command */
			FDX_CreateStatusCmd(server->sent_msg, (SESSION_CLOSE | RESPOND_OK), 0);
			server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;

#if DEBUG_START
			printf("OK...............Stop command received\n");
			fflush(stdout);
#endif
			break;

		case Cmd_DataExchange:
			DataExchange_Handler(groupID, server);

#if DEBUG_START
			printf("OK...............Data exchange command received\n");
			fflush(stdout);
#endif
			break;

		default:
			if(Session_Status == SESSION_OPEN)
			{
				/* Create header frame with incremental sequence number */
				FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
				Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

				FDX_CreateStatusCmd(server->sent_msg, (SESSION_OPEN | RESPOND_NOK), 0);
				server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;

#if DEBUG_START
			printf("NOK...............Unknown command\n");
			fflush(stdout);
#endif
			}
			else
			{
				/* Create header frame with incremental sequence number */
				FDX_CreateFrameHeader(server->sent_msg, Sequance_Number[SEQ_NUM_INDX_STATUS], 1);
				Sequance_Number[SEQ_NUM_INDX_STATUS] += 1;

				FDX_CreateStatusCmd(server->sent_msg, (SESSION_CLOSE | RESPOND_NOK), 0);
				server->total_bytes_to_send = HEADER_SIZE + CMD_STATUS_SIZE;

#if DEBUG_START
			printf("NOK...............No session opened\n");
			fflush(stdout);
#endif
			}
			break;
		}
	}
	else
	{
#if DEBUG_START
		printf("Invalid Message\n");
		fflush(stdout);
#endif
	}
}




void FdxServer_Init(char *ip, uint16_t port)
{
	server.Config.ip 	= (char *)ip;
	server.Config.port 	= port;
	server.Handler 		= FdxServer_Handler;

	//	uint8_t recvBuff[MAX_LINE] = {0};
	//	uint8_t sendBuff[MAX_LINE] = {0};
	//
	//	server.Config.recv_msg = recvBuff;
	//	server.Config.sent_msg = sendBuff;
	//
	//	uint16_t indx = 0;
	//
	//	FDX_Header_t *pFDX_Header = (FDX_Header_t *) server.Config.recv_msg;
	//
	//
	//	pFDX_Header->Signeture = SIGNATURE;
	//	pFDX_Header->MajorVersion = MAJOR_VERSION;
	//	pFDX_Header->MinorVersion = MINOR_VERSION;
	//	pFDX_Header->NumOfCMD = 2;
	//	pFDX_Header->SeqNum = Sequance_Number[SEQ_NUM_INDX_START];
	//
	//
	//
	//	FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *)  &server.Config.recv_msg[CMD_SIZE_OFFSET];
	//
	//	pFDX_DataExchange->CommandSize = CMD_DATA_EXCHANGE_SIZE + 10;
	//	pFDX_DataExchange->CommandCode = Cmd_DataExchange;
	//
	//	pFDX_DataExchange->GroupID = (DIR_APP_TO_GOLDENBOX | PERIPH_ID_DIGITAL_INPUT);
	//
	//	pFDX_DataExchange->DataSize = 10;
	//
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 0] = 1;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 1] = 1;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 2] = 2;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 3] = 0;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 4] = 3;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 5] = 0;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 6] = 4;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 7] = 0;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 8] = 5;
	//	server.Config.recv_msg[CMD_SIZE_OFFSET + CMD_DATA_EXCHANGE_SIZE + 9] = 1;
	//
	//	Session_Status = SESSION_OPEN;
	//
	//	printf("Start of Request frame : \n");
	//	fflush(stdout);
	//
	//	for(indx = 0; indx < 40; ++indx)
	//	{
	//		printf("0x%X\n", server.Config.recv_msg[indx]);
	//	}
	//	printf("end of Request frame\n");
	//	fflush(stdout);

	//
	//	/* Code to be tested */
	//	FdxServer_Handler(&server.Config);



	//	printf("Start of respond frame : \n");
	//	fflush(stdout);
	//
	//	for(indx = 0; indx < 40; ++indx)
	//	{
	//		printf("0x%X\n", server.Config.sent_msg[indx]);
	//	}
	//	printf("end of respond frame\n");
	//	fflush(stdout);

}




void FdxServer_StartForever(void)
{
	Server_Lunch(&server);
}


