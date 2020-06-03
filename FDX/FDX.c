/*
 * FDX.c
 *
 *  Created on: May 27, 2020
 *      Author: ghada
 */

//#include "stdio.h"
//#include "stdint.h"
#include "Std_Types.h"
#include "FDX.h"

#define CMD_SIZE_OFFSET						(16u)
#define CMD_CODE_OFFSET						(18u)
#define DATAEX_GROUPID_OFFSET				(20u)
#define DATAEX_SIZE_OFFSET                  (22u)
#define DATAEX_BYTES_OFFSET                 (24u)


static Std_ReturnType DataExchangeHandler(uint8_t *outbuffer, uint16_t *outbuffersize,
                                          uint8_t *inbuffer,  uint16_t *groupId);

static Std_ReturnType FDX_HeaderCheck(uint8_t *buffer);




/*
 * 	Function Name	: DataExchangeHandler
 * 	Input argu		: *inbuffer, *groupId
 * 	Output argu		: *outbuffer,*outbuffersize
 *	Description		: Static Function that handles exchanged date the comes from the received frame  
 * 	return			: result
 */
static Std_ReturnType DataExchangeHandler(uint8_t *outbuffer, uint16_t *outbuffersize,
                                          uint8_t *inbuffer,  uint16_t *groupId)
{
	Std_ReturnType result = 0;

	uint16_t bufferIndx = 0;
	*outbuffersize = (uint16_t) inbuffer[DATAEX_SIZE_OFFSET];
	*groupId = (uint16_t) inbuffer[DATAEX_GROUPID_OFFSET];

	for(bufferIndx = 0; bufferIndx < inbuffer[DATAEX_SIZE_OFFSET]; ++inbuffer[DATAEX_SIZE_OFFSET])
	{
		outbuffer[bufferIndx] = (uint8_t) inbuffer[DATAEX_BYTES_OFFSET + bufferIndx];
	}

	return result;
}

/*
 * 	Function Name	: FDX_HeaderCheck
 * 	Input argu		: *buffer
 * 	Output argu		: None
 *	Description		: Static Function checks that the received header is valid or not
 * 	return			: result
 */
static Std_ReturnType FDX_HeaderCheck(uint8_t *buffer)
{
	uint8_t result = E_OK;
	FDX_Header_t *pFXD_Header = (FDX_Header_t *)buffer;

	if(pFXD_Header != NULL)
	{
		/* Assemble Header */
		if(pFXD_Header->Signeture == SIGNATURE)
		{
			if((pFXD_Header->MajorVersion == MAJOR_VERSION) && (pFXD_Header->MinorVersion == MINOR_VERSION))
			{
				if(pFXD_Header->NumOfCMD !=  0)
				{
					result = E_OK;
				}
				else
				{
					result = E_NOT_OK;
				}


			}
			else
			{
				result = E_NOT_OK;
			}

		}
		else
		{
			result = E_NOT_OK;
		}
	}
	else
	{
		result = E_NOT_OK;
	}

	return result;
}


/*
 * 	Function Name	: FDX_ParsingFrame
 * 	Input argu		: *inbuffer, inbuffersize
 * 	Output argu		: *frametype,*outbuffer,*outbuffersize
 *  Description		: This Function checks the header, extracts command size and code ,checks command type and handles command cases
 * 	return			: result
 */
Std_ReturnType FDX_ParsingFrame(uint8_t *inbuffer, uint16_t inbuffersize,
		                        uint16_t *frametype, uint8_t *outbuffer,
								uint16_t *outbuffersize, uint16_t *groupId)
{
	Std_ReturnType result = E_OK;

	// call fun to check header
	result = FDX_HeaderCheck(inbuffer);

	if(result == E_NOT_OK)
	{
		*frametype = 0; 
	}

	//exteract command size and code
	else
	{
		//data size assigned it at out buffer size
		//*outbuffersize = (uint16_t) inbuffer[CMD_SIZE_OFFSET];

		*frametype = (uint16_t) inbuffer[CMD_CODE_OFFSET];
		//check for command

		switch(*frametype)
		{
		case Cmd_Start:
			/* call static start frame handler */
			break;
		case Cmd_Stop:
			/* call static start frame handler */
			break;
		case Cmd_DataExchange:
			/* call static Data exchange handler */
			DataExchangeHandler(outbuffer, outbuffersize, inbuffer, groupId);
			break;

		case Cmd_DataRequest:

			break;

		case Cmd_Status:

			break;

		default:
			break;
		}
	}

	return result;

}


/*
 * 	Function Name	: FDX_CreateStartFrame
 * 	Input argu		: *buffer, seqNum
 * 	Output argu		: None
 *  Description		: This Function sets the header, command code and command size
 * 	return			: result
 */
Std_ReturnType FDX_CreateStartFrame(uint8_t *buffer, uint16_t seqNum)
{
	uint8_t result = E_OK;
	FXD_Start_t *pFXD_Start = (FXD_Start_t *)buffer;

	if(pFXD_Start != NULL)
	{
		/* Assemble Header */
		pFXD_Start->Header.Signeture 		= (uint64_t) SIGNATURE;
		pFXD_Start->Header.MajorVersion 	= (uint8_t)  MAJOR_VERSION;
		pFXD_Start->Header.MinorVersion 	= (uint8_t)  MINOR_VERSION;
		pFXD_Start->Header.NumOfCMD 		= (uint16_t) NUM_OF_CMD;
		pFXD_Start->Header.SeqNum 			= (uint16_t) seqNum;
		pFXD_Start->Header.Reserved 		= (uint16_t) RESERVED_VALUE;

		/* Add command */
		pFXD_Start->CommandSize 			= (uint16_t) CMD_START_SIZE;
		pFXD_Start->CommandCode 			= (uint16_t) Cmd_Start;
	}

	else
	{
		result = E_NOT_OK;
	}

	return result;
}




/*
 * 	Function Name	: FDX_CreateStopFrame
 * 	Input argu		: *buffer, seqNum
 * 	Output argu		: None
 *  Description		: This Function sets the header ,command code and command size
 * 	return			: result
 */
extern Std_ReturnType FDX_CreateStopFrame(uint8_t *buffer, uint16_t seqNum)
{
	uint8_t result = E_OK;
	FDX_Stop_t *pFDX_Stop = (FDX_Stop_t *)buffer;

	if(pFDX_Stop != NULL)
	{
		/* Assemble Header */
		pFDX_Stop->Header.Signeture			= (uint64_t) SIGNATURE;
		pFDX_Stop->Header.MajorVersion		= (uint8_t)  MAJOR_VERSION;
		pFDX_Stop->Header.MinorVersion		= (uint8_t)  MINOR_VERSION;
		pFDX_Stop->Header.NumOfCMD			= (uint16_t) NUM_OF_CMD;
		pFDX_Stop->Header.SeqNum			= (uint16_t) seqNum;
		pFDX_Stop->Header.Reserved			= (uint16_t) RESERVED_VALUE;

		/* Add command */
		pFDX_Stop->CommandSize				= (uint16_t) CMD_STOP_SIZE;
		pFDX_Stop->CommandCode				= (uint16_t) Cmd_Stop;

	}

	else
	{
		result = E_NOT_OK;
	}

	return result;
}





/*
 * 	Function Name	: FDX_CreateDataExchangeFrame
 * 	Input argu		: *buffer, seqNum,uint16_t groupid ,dataSize,dataBytes
 * 	Output argu		: None
 *  Description		: This Function Creates Data Exchange Frame by setting header, datasize, databytes and groupID
 * 	return			: result
 */
Std_ReturnType FDX_CreateDataExchangeFrame(uint8_t  *buffer,  uint16_t seqNum, uint16_t groupID,
		                                   uint16_t dataSize, uint8_t  *dataBytes)

{
	uint8_t result = E_OK;
	FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *) buffer;

	if(pFDX_DataExchange != NULL)
	{
		/* Assemble Header */
		pFDX_DataExchange->Header.Signeture		= (uint64_t) SIGNATURE;
		pFDX_DataExchange->Header.MajorVersion	= (uint8_t)  MAJOR_VERSION;
		pFDX_DataExchange->Header.MinorVersion	= (uint8_t)  MINOR_VERSION;
		pFDX_DataExchange->Header.NumOfCMD		= (uint16_t) NUM_OF_CMD;
		pFDX_DataExchange->Header.SeqNum		= (uint16_t) seqNum;
		pFDX_DataExchange->Header.Reserved		= (uint16_t) RESERVED_VALUE;

		/* Add command */
		pFDX_DataExchange->CommandSize			= CMD_DATA_EXCHANGE_SIZE;
		pFDX_DataExchange->CommandCode			= (uint16_t) Cmd_DataExchange;
		pFDX_DataExchange->GroupID				= groupID;
		pFDX_DataExchange->DataSize				= dataSize;

		for(uint16_t dataindex=0;dataindex<dataSize;dataindex++)
		{
			pFDX_DataExchange->DataBytes[dataindex] = (uint8_t)dataBytes[dataindex]; //need to modify this part
		}
	}

	else
	{
		result = E_NOT_OK;
	}
	return result;
}


/*
 * 	Function Name	: FDX_CreateDataExchangeFrame
 * 	Input argu		: *buffer, seqNum,uint16_t groupID
 * 	Output argu		: None
 *  Description		: This Function Creates Data Request Frame by setting headers command code command size and groupID
 * 	return			: result
 */
Std_ReturnType FDX_CreateDataRequestFrame(uint8_t *buffer, uint16_t seqNum, uint16_t groupID)
{
	uint8_t result = E_OK;
	FDX_DataRequest_t *pFDX_DataRequest = (FDX_DataRequest_t *)buffer;

	if(pFDX_DataRequest != NULL)
	{
		/* Assemble Header */
		pFDX_DataRequest->Header.Signeture		= (uint64_t) SIGNATURE;
		pFDX_DataRequest->Header.MajorVersion	= (uint8_t)  MAJOR_VERSION;
		pFDX_DataRequest->Header.MinorVersion	= (uint8_t)  MINOR_VERSION;
		pFDX_DataRequest->Header.NumOfCMD		= (uint16_t) NUM_OF_CMD;
		pFDX_DataRequest->Header.SeqNum		= (uint16_t) seqNum;
		pFDX_DataRequest->Header.Reserved		= (uint16_t) RESERVED_VALUE;

		/* Add command */
		pFDX_DataRequest->CommandSize			= (uint16_t) CMD_DATA_REG_SIZE;
		pFDX_DataRequest->CommandCode			= (uint16_t) Cmd_DataRequest;
		pFDX_DataRequest->GroupID 				= (uint16_t) groupID;

	}

	else
	{
		result = E_NOT_OK;
	}

	return result;

}


/*
 * 	Function Name	: FDX_CreateDataExchangeFrame
 * 	Input argu		: buffer, seqNum, status, timeStamp
 * 	Output argu		: None
 *  Description		: This Function Creates Status Frame by setting headers command code command size ,status and time stamp
 * 	return			: result
 */
Std_ReturnType FDX_CreateStatusFrame(uint8_t *buffer, uint16_t seqNum, uint16_t status, uint64_t timeStamp)
{
	uint8_t result = E_OK;
	FDX_Status_t *pFDX_Status = (FDX_Status_t *)buffer;

	if(pFDX_Status != NULL)
	{
		/* Assemble Header */
		pFDX_Status->Header.Signeture		= (uint64_t) SIGNATURE;
		pFDX_Status->Header.MajorVersion	= (uint8_t)  MAJOR_VERSION;
		pFDX_Status->Header.MinorVersion	= (uint8_t)  MINOR_VERSION;
		pFDX_Status->Header.NumOfCMD		= (uint16_t) NUM_OF_CMD;
		pFDX_Status->Header.SeqNum			= (uint16_t) seqNum;
		pFDX_Status->Header.Reserved		= (uint16_t) RESERVED_VALUE;

		/* Add command */
		pFDX_Status->CommandSize			= (uint16_t) CMD_STATUS_SIZE;
		pFDX_Status->CommandCode			= (uint16_t) Cmd_Status;
		pFDX_Status->Status					= (uint16_t) status;
		pFDX_Status->Reserved				= (uint16_t) RESERVED_VALUE;
		pFDX_Status->TimeStamp				= (uint64_t) timeStamp;
	}

	else
	{
		result = E_NOT_OK;
	}

	return result;
}
