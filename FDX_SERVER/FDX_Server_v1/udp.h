/*
 * udp.h
 *
 *  Created on: May 28, 2020
 *      Author: midoj
 */

#ifndef UDP_H_
#define UDP_H_


#define MAX_LINE 				1024u

#define OK						0x01u
#define N_OK					0x02u




typedef struct{
	char *		ip;
	uint16_t	port;
	uint8_t *	recv_msg;
	uint16_t	total_bytes_received;
	uint8_t *	sent_msg;
	uint16_t	total_bytes_sent;
	uint16_t	total_bytes_to_send;
}Server_Config_t;

typedef void(*Handler_t)(Server_Config_t *pServer_Config);

typedef struct{
	Server_Config_t 	Config;
	Handler_t			Handler;
}UDP_Server;


typedef struct{
	char *		ip;
	uint16_t 	port;
	uint8_t *	request_msg;
	uint16_t	request_msg_size;
	uint8_t *	response_msg;
	uint16_t	total_bytes_received;
	uint8_t 	wait_for_response;
	uint32_t	timeout;
}UDP_Client;






extern void Client_Request(UDP_Client *client);
extern void Server_Lunch(UDP_Server *server);




#endif /* UDP_H_ */
