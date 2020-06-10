/**
 * @file FDX.h
 * @author Family
 * @brief This file is the Header file of FDX protocol
 * @version 0.1
 * @date 2020-06-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef FDX_INTERFACE_H_
#define FDX_INTERFACE_H_

/**
 * @brief The standerd types 
 * 
 */

typedef uint8_t Std_ReturnType;

#define E_OK			0x00u
#define E_NOT_OK		0x01u

#define STD_HIGH		0x01u
#define STD_LOW			0x00u

#define STD_ACTIVE		0x01u
#define STD_IDLE		0x00u

#define STD_ON			0x01u
#define STD_OFF			0x00u


/**
 * @brief The Header info, the signature stands for CAGNAMSP
 * 
 */
 
#define SIGNATURE							0x4341474e414d5350
#define MAJOR_VERSION						1
#define MINOR_VERSION 						0
#define RESERVED_VALUE						0

/**
 * @brief The commands sizes 
 * 
 */
#define HEADER_SIZE							(16u)
#define CMD_START_SIZE               		(4u)
#define CMD_STOP_SIZE                		(4u)
#define CMD_DATA_EXCHANGE_SIZE				(8u)
#define CMD_DATA_REG_SIZE                  	(6u)
#define CMD_STATUS_SIZE						(16u)



#define CMD_SIZE_OFFSET						(16u)
#define CMD_CODE_OFFSET						(18u)
#define DATAEX_GROUPID_OFFSET				(20u)
#define DATAEX_SIZE_OFFSET                  (22u)
#define DATAEX_BYTES_OFFSET                 (24u)




/**
 * @brief the frame direction
 * 
 */
#define DIR_GOLDENBOX_TO_APP 			0x0A00
#define DIR_APP_TO_GOLDENBOX 			0x0B00

#define GET_DIR(GROUP_ID)				(GROUP_ID & 0xFF00)



/**
 * @brief the Peripheral ID
 * 
 */
#define PERIPH_ID_INVALID				(0x0000u)
#define PERIPH_ID_DIGITAL_INPUT  		(0x0001u)
#define PERIPH_ID_DIGITAL_OUTPUT 		(0x0002u)

#define GET_PERIPH_ID(GROUP_ID)			(GROUP_ID & 0x00FF)


/**
 * @brief the status indicators
 *
 */

#define SESSION_OPEN 			(0x2400U)
#define SESSION_CLOSE 			(0x8600U)

#define RESPOND_OK				(0x007EU)
#define RESPOND_NOK				(0x00FFU)



/**
 * @brief This enum Holds the Types of command code 
 * 
 */
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


/**
 * @brief The header structure
 * 
 */
#pragma pack(2)					
typedef struct{
	uint64_t Signeture;
	uint8_t  MajorVersion;		
	uint8_t  MinorVersion;		
	uint16_t NumOfCMD;
	uint16_t SeqNum;
	uint16_t Reserved;
}FDX_Header_t;

/**
 * @brief The start structure
 * 
 */
#pragma pack(2)
typedef struct {

	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
}FDX_Start_t;

/**
 * @brief The stop structure
 * 
 */
#pragma pack(2)
typedef struct{

	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
}FDX_Stop_t;

/**
 * @brief The data exchange structure
 * 
 */
#pragma pack(2)
typedef struct{

	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		GroupID;
	uint16_t 		DataSize;
	uint8_t 		DataBytes;
}FDX_DataExchange_t;

/**
 * @brief The data request structure
 * 
 */
#pragma pack(2)
typedef struct{

	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		GroupID;
}FDX_DataRequest_t;

/**
 * @brief The status structure
 * 
 */
#pragma pack(2)
typedef struct{

	uint16_t 		CommandSize;
	uint16_t 		CommandCode;
	uint16_t 		Status;
	uint16_t 		Reserved;
	uint64_t 		TimeStamp;
}FDX_Status_t;


/**
 * @brief Digital input channels structure
 * 
 */
typedef struct{
	uint8_t   CHANNEL_0;
	uint8_t   CHANNEL_1;
	uint8_t   CHANNEL_2;
	uint8_t   CHANNEL_3;
	uint8_t   CHANNEL_4;
	uint8_t   CHANNEL_5;
	uint8_t   CHANNEL_6;
	uint8_t   CHANNEL_7;

}Digital_Input_t;


/**
 * @brief Digital output channels structure
 * 
 */
typedef struct{
	uint8_t  CHANNEL_0;
	uint8_t  CHANNEL_1;
	uint8_t  CHANNEL_2;
	uint8_t  CHANNEL_3;
	uint8_t  CHANNEL_4;
	uint8_t  CHANNEL_5;
	uint8_t  CHANNEL_6;
	uint8_t  CHANNEL_7;

}Digital_Output_t;

/**
 * @brief                 This Function creates the Start cmd of the frame
 */
extern Std_ReturnType FDX_CreateStartCmd(uint8_t *buffer);



/**
 * @brief                 This Function creates the Stop cmd of the frame
 */

extern Std_ReturnType FDX_CreateStopCmd(uint8_t *buffer);


/**
 * @brief                 This Function creates data exchange commad 
 */

extern Std_ReturnType FDX_CreateDataExchangeCmd(uint8_t  *outputBuffer, uint16_t groupID,
        uint16_t dataSize, uint8_t  *dataBytes);

/**
 * @brief                 This Function creates data request commad 
 */

extern Std_ReturnType FDX_CreateDataRequestCmd(uint8_t *buffer, uint16_t seqNum, uint16_t GroupID);

/**
 * @brief                 This Function creates Status command
 */
extern Std_ReturnType FDX_CreateStatusCmd(uint8_t *outputBuffer, uint16_t status, uint64_t timeStamp);

/**
 * @brief                  This Function Specifies the Frame type 
 */
extern Std_ReturnType FDX_ParsingFrame(uint8_t *inbuffer,
		uint16_t *frametype,
		uint16_t *datasize, uint16_t *groupId);


/**
 * @brief                 This Function creates the header of the frame
 */
extern  Std_ReturnType FDX_CreateFrameHeader(uint8_t *buffer, uint16_t seqNum, uint16_t numOfCmd);


#endif /* FDX_INTERFACE_H_ */
