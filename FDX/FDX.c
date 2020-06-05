/**
 * @file FDX.c
 * @author Family
 * @brief This file is the implementation of FDX protocol
 * @version 0.1
 * @date 2020-06-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "stdio.h"
#include "stdint.h"

#include "FDX.h"





static Std_ReturnType HeaderCheck(uint8_t *buffer);
static Std_ReturnType DataExchangeHandler(uint16_t *Datasize, uint8_t *inbuffer, uint16_t *groupId);








/**
 * @brief                 This Function Checks whether the Header is valid or not
 * 
 * @param buffer          Holds the frame 
 * @return Std_ReturnType returns E_OK if there is a valid header and  E_Not_OK if there is invalid header
 */
static Std_ReturnType HeaderCheck(uint8_t *buffer)
{
	Std_ReturnType errorStatus = E_OK;
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
					errorStatus = E_OK;
				}
				else
				{
					errorStatus = E_NOT_OK;
				}
			}
			else
			{
				errorStatus = E_NOT_OK;
			}

		}
		else
		{
			errorStatus = E_NOT_OK;
		}
	}
	else
	{
		errorStatus = E_NOT_OK;
	}

	return errorStatus;
}


/**
 * @brief                  This Function Specifies the Frame type 
 * 
 * @param inbuffer         Holds The input Frame
 * @param frametype        Holds The Command Code
 * @param datasize         Holds The number of bytes of the data
 * @param groupId          Holds the Frame direction and peripheral number
 * @return  Std_ReturnType returns E_OK if there is a valid header and E_Not_OK if there is invalid header 
 */
Std_ReturnType FDX_ParsingFrame(uint8_t *inbuffer, uint16_t *frametype, uint16_t *datasize, uint16_t *groupId)
{
	Std_ReturnType errorStatus = E_OK;

	/* Checks if the Header is valid or not*/
	errorStatus = HeaderCheck(inbuffer);

	if(errorStatus == E_NOT_OK)
	{
		*frametype = 0; 
	}

	
	else
	{
	
		*frametype = (uint16_t) inbuffer[CMD_CODE_OFFSET];
		/*check the command code*/

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
			DataExchangeHandler(datasize, inbuffer, groupId);
			break;

		case Cmd_DataRequest:

			break;

		case Cmd_Status:

			break;

		default:
			break;
		}
	}

	return errorStatus;

}


/**
 * @brief                 This Function creates the Start cmd of the frame
 * 
 * @param buffer          Holds the input Frame
 * @return Std_ReturnType returns E_OK if there is a start command and E_Not_OK if there is no start command
 */
Std_ReturnType FDX_CreateStartCmd(uint8_t *buffer)
{
	Std_ReturnType errorStatus = E_OK;
	FDX_Start_t *pFXD_Start = (FDX_Start_t *)&buffer[CMD_SIZE_OFFSET];

	if(pFXD_Start != NULL)
	{
		/* Assign command code and command size */
		pFXD_Start->CommandSize 			= (uint16_t) CMD_START_SIZE;
		pFXD_Start->CommandCode 			= (uint16_t) Cmd_Start;
	}

	else
	{
		errorStatus = E_NOT_OK;
	}

	return errorStatus;
}



/**
 * @brief                 This Function creates the Stop cmd of the frame
 * 
 * @param buffer          Holds the input Frame
 * @return Std_ReturnType returns E_OK if there is a stop command and E_Not_OK if there is no stop command
*/
extern Std_ReturnType FDX_CreateStopCmd(uint8_t *buffer)
{
	Std_ReturnType errorStatus = E_OK;
	FDX_Stop_t *pFDX_Stop = (FDX_Stop_t *)&buffer[CMD_SIZE_OFFSET];

	if(pFDX_Stop != NULL)
	{
		
		/* Assign command code and command size */
		pFDX_Stop->CommandSize				= (uint16_t) CMD_STOP_SIZE;
		pFDX_Stop->CommandCode				= (uint16_t) Cmd_Stop;

	}

	else
	{
		errorStatus = E_NOT_OK;
	}

	return errorStatus;
}





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
Std_ReturnType FDX_CreateDataExchangeCmd(uint8_t  *buffer, uint16_t groupID,
		                                   uint16_t dataSize, uint8_t  *dataBytes)

{
	Std_ReturnType errorStatus = E_OK;
	FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *) &buffer[CMD_SIZE_OFFSET];

	if(pFDX_DataExchange != NULL)
	{
		
		/* Assign command code, command size,GroupID and Data size */
		pFDX_DataExchange->CommandSize			= CMD_DATA_EXCHANGE_SIZE;
		pFDX_DataExchange->CommandCode			= (uint16_t) Cmd_DataExchange;
		pFDX_DataExchange->GroupID				= groupID;
		pFDX_DataExchange->DataSize				= dataSize;

		pFDX_DataExchange->DataBytes= *((uint8_t*)dataBytes); 

	}

	else
	{
		errorStatus = E_NOT_OK;
	}
	return errorStatus;
}


/**
 * @brief                 This Function creates data request commad 
 * 
 * @param buffer          Holds the input frame
 * @param seqNum          Holds the frame order 
 * @param groupID         Holds the Frame direction and peripheral number
 * @return Std_ReturnType returns E_OK if there is a data request command and E_Not_OK if there is no data request command
 */
Std_ReturnType FDX_CreateDataRequestCmd(uint8_t *buffer, uint16_t seqNum, uint16_t groupID)
{
	Std_ReturnType errorStatus = E_OK;
	FDX_DataRequest_t *pFDX_DataRequest = (FDX_DataRequest_t *)&buffer[CMD_SIZE_OFFSET];

	if(pFDX_DataRequest != NULL)
	{
		
		/* Assign command code, command size and GroupID  */
		pFDX_DataRequest->CommandSize			= (uint16_t) CMD_DATA_REG_SIZE;
		pFDX_DataRequest->CommandCode			= (uint16_t) Cmd_DataRequest;
		pFDX_DataRequest->GroupID 				= (uint16_t) groupID;

	}

	else
	{
		errorStatus = E_NOT_OK;
	}

	return errorStatus;

}


/**
 * @brief                 This Function creates Status command
 * 
 * @param buffer          Holds the input frame
 * @param seqNum          Holds the frame order
 * @param status          Holds the frame state 
 * @param timeStamp       Holds the estimated action time
 * @return Std_ReturnType returns E_OK if there is a data request command and E_Not_OK if there is no data request command
 */
Std_ReturnType FDX_CreateStatusCmd(uint8_t *buffer, uint16_t status, uint64_t timeStamp)
{
	Std_ReturnType errorStatus = E_OK;
	FDX_Status_t *pFDX_Status = (FDX_Status_t *)&buffer[CMD_SIZE_OFFSET];

	if(pFDX_Status != NULL)
	{
	
		/* Assign command Info */
		pFDX_Status->CommandSize			= (uint16_t) CMD_STATUS_SIZE;
		pFDX_Status->CommandCode			= (uint16_t) Cmd_Status;
		pFDX_Status->Status					= (uint16_t) status;
		pFDX_Status->Reserved				= (uint16_t) RESERVED_VALUE;
		pFDX_Status->TimeStamp				= (uint64_t) timeStamp;
	}

	else
	{
		errorStatus = E_NOT_OK;
	}

	return errorStatus;
}

/**
 * @brief                 This Function extracts the Group ID and Data size
 * 
 * @param Datasize        Holds the number of data bytes
 * @param inbuffer        Holds the input frame
 * @param groupId         Holds the Frame direction and peripheral number
 * @return Std_ReturnType returns E_OK if there is a received frame and E_Not_OK if there is no received frame
 */


static Std_ReturnType DataExchangeHandler(uint16_t *Datasize, uint8_t *inbuffer, uint16_t *groupId)
{
    Std_ReturnType errorStatus = E_OK;
    FDX_DataExchange_t *pFDX_DataExchange = (FDX_DataExchange_t *)&inbuffer[DATAEX_GROUPID_OFFSET] ;
    /* check if there is a received data*/
    if(inbuffer != NULL)
    {  
        /*Get group ID */
        *groupId = pFDX_DataExchange->GroupID;

        /*assign data size*/
       *Datasize = pFDX_DataExchange->DataSize;

       
    }
    else
    {
        errorStatus = E_NOT_OK;
    }
    
    return errorStatus;
}


/**
 * @brief                 This Function creates the header of the frame
 * 
 * @param buffer          Holds the input frame 
 * @param seqNum          Holds the frame order
 * @return Std_ReturnType returns E_OK if there a frame header and E_Not_OK if there is no a frame header
 */
 Std_ReturnType FDX_CreateFrameHeader(uint8_t *buffer, uint16_t seqNum)
{

	Std_ReturnType errorStatus = E_OK;
	FDX_Header_t *pFDX_Header = (FDX_Header_t *)buffer;

	if(pFDX_Header != NULL)
	{
		/* Assemble Header */
		pFDX_Header->Signeture 		= (uint64_t) SIGNATURE;
		pFDX_Header->MajorVersion 	= (uint8_t)  MAJOR_VERSION;
		pFDX_Header->MinorVersion 	= (uint8_t)  MINOR_VERSION;
		pFDX_Header->NumOfCMD 		= (uint16_t) NUM_OF_CMD;
		pFDX_Header->SeqNum 		= (uint16_t) seqNum;
		pFDX_Header->Reserved 		= (uint16_t) RESERVED_VALUE;
  }
	else
	{
		errorStatus = E_NOT_OK;
	}
	return errorStatus;
}
