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
#define NUM_OF_CMD							1
#define RESERVED_VALUE						0

/**
 * @brief The commands sizes 
 * 
 */
#define CMD_START_SIZE               		(4u)
#define CMD_STOP_SIZE                		(4u)
#define CMD_DATA_EXCHANGE_SIZE				(10u)
#define CMD_DATA_REG_SIZE                  	(6u)
#define CMD_STATUS_SIZE						(16u)

/**
 * @brief the frame direction
 * 
 */
#define DIR_GOLDENBOX_TO_APP 0
#define DIR_APP_TO_GOLDENBOX 1

/**
 * @brief the Peripheral ID
 * 
 */

#define PERIPH_ID_DIGITAL_INPUT  0
#define PERIPH_ID_DIGITAL_OUTPUT 1



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
}FXD_Start_t;

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
 * 
 * @param buffer          Holds the input Frame
 * @param seqNum          Holds the frame order 
 * @return Std_ReturnType returns E_OK if there is a start command and E_Not_OK if there is no start command
 */
extern Std_ReturnType FDX_CreateStartCmd(uint8_t *buffer, uint16_t seqNum);



/**
 * @brief                 This Function creates the Stop cmd of the frame
 * 
 * @param buffer          Holds the input Frame
 * @param seqNum          Holds the frame order 
 * @return Std_ReturnType returns E_OK if there is a stop command and E_Not_OK if there is no stop command
 */

extern Std_ReturnType FDX_CreateStopCmd(uint8_t *buffer, uint16_t seqNum);


/**
 * @brief                 This Function creates data exchange commad 
 * 
 * @param buffer          Holds the input frame
 * @param seqNum          Holds the frame order 
 * @param groupID         Holds the Frame direction and peripheral number
 * @param dataSize        Holds The number of bytes of the data
 * @param dataBytes       Holds the data
 * @return Std_ReturnType returns E_OK if there is a data exchange command and E_Not_OK if there is no data exchange command
 */

extern Std_ReturnType FDX_CreateDataExchangeCmd(uint8_t *buffer ,uint16_t seqNum, uint16_t GroupID,uint16_t DataSize,uint8_t *DataBytes);

/**
 * @brief                 This Function creates data request commad 
 * 
 * @param buffer          Holds the input frame
 * @param seqNum          Holds the frame order 
 * @param groupID         Holds the Frame direction and peripheral number
 * @return Std_ReturnType returns E_OK if there is a data request command and E_Not_OK if there is no data request command
 */

extern Std_ReturnType FDX_CreateDataRequestCmd(uint8_t *buffer, uint16_t seqNum, uint16_t GroupID);

/**
 * @brief                 This Function creates Status command
 * 
 * @param buffer          Holds the input frame
 * @param seqNum          Holds the frame order
 * @param status          Holds the frame state 
 * @param timeStamp       Holds the estimated action time
 * @return Std_ReturnType returns E_OK if there is a data request command and E_Not_OK if there is no data request command
 */
extern Std_ReturnType FDX_CreateStatusCmd(uint8_t *buffer, uint16_t seqNum, uint16_t status, uint64_t timeStamp);


/**
 * @brief                  This Function Specifies the Frame type 
 * 
 * @param inbuffer         Holds The input Frame
 * @param frametype        Holds The Command Code
 * @param datasize         Holds The number of bytes of the data
 * @param groupId          Holds the Frame direction and peripheral number
 * @return  Std_ReturnType returns E_OK if there is a valid header and E_Not_OK if there is invalid header 
 */
extern Std_ReturnType FDX_ParsingFrame(uint8_t *inbuffer, 
		uint16_t *frametype,
		uint16_t *datasize, uint16_t *groupId);


/**
 * @brief                 This Function creates the header of the frame
 * 
 * @param buffer          Holds the input frame 
 * @param seqNum          Holds the frame order
 * @return Std_ReturnType returns E_OK if there a frame header and E_Not_OK if there is no a frame header
 */
extern  Std_ReturnType FDX_CreateFrameHeader(uint8_t *buffer, uint16_t seqNum);


#endif /* FDX_INTERFACE_H_ */
