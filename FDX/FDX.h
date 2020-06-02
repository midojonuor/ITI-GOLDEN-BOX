/*
 * FDX_Interface.h
 *
 *  Created on: May 26, 2020
 *      Author: ghada
 */

#ifndef FDX_INTERFACE_H_
#define FDX_INTERFACE_H_

typedef uint8_t Std_ReturnType;

#define E_OK			0x00u
#define E_NOT_OK		0x01u

#define STD_HIGH		0x01u
#define STD_LOW			0x00u

#define STD_ACTIVE		0x01u
#define STD_IDLE		0x00u

#define STD_ON			0x01u
#define STD_OFF			0x00u




/* CAGNAMSP signature */
#define SIGNATURE							0x4341474e414d5350
#define MAJOR_VERSION						1
#define MINOR_VERSION 						0
#define NUM_OF_CMD							1
#define RESERVED_VALUE						0



#define CMD_START_SIZE               		(4u)
#define CMD_STOP_SIZE                		(4u)
#define CMD_DATA_EXCHANGE_SIZE				(10u)
#define CMD_DATA_REG_SIZE                  	(6u)
#define CMD_STATUS_SIZE						(16u)



enum{
	Cmd_Start             = 0x0001,
	Cmd_Stop              = 0x0002,
	Cmd_Key               = 0x0003,
	Cmd_DataRequest       = 0x0006,
	Cmd_DataExchange      = 0x0005,
	Cmd_DataError         = 0x0007,
	Cmd_FreeRunning       = 0x0008,
	Cmd_FreeRunningCancel = 0x0009,
	Cmd_Status            = 0x0004,
	Cmd_StatusRequest     = 0x000A,
	Cmd_SeqNumError       = 0x000B,
}FdxCommandE;

#pragma pack(2)					// needed to padding all structure element to 2 bytes
typedef struct{
	uint64_t Signeture;
	uint8_t  MajorVersion;		// This field is 1 byte only, sorry :)
	uint8_t  MinorVersion;		// This field is 1 byte only, sorry :)
	uint16_t NumOfCMD;
	uint16_t SeqNum;
	uint16_t Reserved;
}FDX_Header_t;

#pragma pack(2)
typedef struct {
	FDX_Header_t 	Header;
	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
}FXD_Start_t;

#pragma pack(2)
typedef struct{
	FDX_Header_t 	Header;
	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
}FDX_Stop_t;


#pragma pack(2)
typedef struct{
	FDX_Header_t 	Header;
	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		GroupID;
	uint16_t 		DataSize;
	uint8_t *		DataBytes;
}FDX_DataExchange_t;


#pragma pack(2)
typedef struct{
	FDX_Header_t 	Header;
	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		GroupID;
}FDX_DataRequest_t;

#pragma pack(2)
typedef struct{
	FDX_Header_t 	Header;
	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		Status;
	uint16_t 		Reserved;
	uint64_t 		TimeStamp;
}FDX_Status_t;



extern Std_ReturnType FDX_CreateStartFrame(uint8_t *buffer, uint16_t seqNum);
extern Std_ReturnType FDX_ParsingFrame(uint8_t *inbuffer, uint16_t inbuffersize,
		uint16_t *frametype, uint8_t *outbuffer, uint16_t *outbuffersize, uint16_t *groupId);
extern Std_ReturnType FDX_StopFram(uint8_t *buffer, uint16_t seqNum);
extern Std_ReturnType FDX_DataExchangeFrame(uint8_t *buffer ,uint16_t seqNum, uint16_t GroupID,uint16_t DataSize,uint8_t *DataBytes);
extern Std_ReturnType FDX_DataRequestFrame(uint8_t *buffer, uint16_t seqNum, uint16_t GroupID);
extern Std_ReturnType FDX_StatusFrame(uint8_t *buffer, uint16_t seqNum, uint16_t status, uint64_t timeStamp);



#endif /* FDX_INTERFACE_H_ */
