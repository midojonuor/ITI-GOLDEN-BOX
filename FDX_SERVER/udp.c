/*
 * udp.c
 *
 *  Created on: May 28, 2020
 *      Author: midoj
 */


#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "sys/time.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "netdb.h"

#include "stdint.h"
#include "udp.h"




void Client_Request(UDP_Client *client)
{
	/* socket file descriptor */
	int clientSocket;
	struct sockaddr_in servAddr;
	socklen_t sockAddrLen = sizeof(struct sockaddr_in);

	uint8_t recvBuff[MAX_LINE] = {0};

	/* time variable for timeout */
	struct timeval timeout;



	/* Creating socket file descriptor */
	clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if ( clientSocket < 0 )
	{
		printf("Socket creation failed");
		perror("Socket creation failed");
	}



	/* Clear serverAddress structure */
	memset(&servAddr, 0, sizeof(servAddr));

	/* Filling server information */
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr((const char *)client->ip);
	servAddr.sin_port = htons(client->port);


	sendto(clientSocket,
			(const char *)client->request_msg,
			client->request_msg_size,
			0,
			(const struct sockaddr *) &servAddr,
			sizeof(servAddr));

	client->total_bytes_received = 0;

	if(OK == client->wait_for_response)
	{
		timeout.tv_sec = client->timeout;
		timeout.tv_usec = 0;

		setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&timeout, sizeof(struct timeval));



		client->total_bytes_received = recvfrom(clientSocket,
				(uint8_t *) recvBuff,
				MAX_LINE,
				0,
				(struct sockaddr *)&servAddr,
				&sockAddrLen);

	}
	close(clientSocket);
}






void Server_Lunch(UDP_Server *server)
{
	/* socket file descriptor */
	int socketServer;

//	struct hostent *hostp;		/* client host info */
//	char *hostaddrp;			/* dotted decimal host addr string */

	/* buffer to receive requests */
	uint8_t requestMsgBuffer[MAX_LINE];
	uint8_t responseMsgBuffer[MAX_LINE];

	server->Config.recv_msg 	= requestMsgBuffer;
	server->Config.sent_msg 	= responseMsgBuffer;

	struct sockaddr_in serverAddress, clientAddress;
	int clientLen = sizeof(clientAddress);
	int bindStatus = 0;

	/* Clear structures of socket addresses */
	memset(&serverAddress, 0, sizeof(serverAddress));
	memset(&clientAddress, 0, sizeof(clientAddress));

	socketServer = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if( socketServer < 0 )
	{
		printf("Socket creation failed\n");
		perror("Socket creation failed");
		return;
	}


	/* Assign server information */
	serverAddress.sin_family 		= PF_INET;
	serverAddress.sin_addr.s_addr	= inet_addr(server->Config.ip);		/* Convert string to binary address format (inet_ntop do the opposite) */
	serverAddress.sin_port 			= htons(server->Config.port);

	/* Bind socket with server address */
	bindStatus = bind(socketServer, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	if ( bindStatus < 0 )
	{
		printf("\nBind failed.");
		perror("Bind failed.");
	}
	else
	{
		printf("UDP Server up and listening.......\n");
		fflush(stdout);

		/* do forever */
		while(1)
		{
			/* receive a UDP datagram from a client */
			server->Config.total_bytes_received = recvfrom(socketServer,
					requestMsgBuffer,
					MAX_LINE,
					0,
					(struct sockaddr *)&clientAddress,
					&clientLen);

			/* determine who set the datagram */

//			hostp = gethostbyaddr((const char *)&clientAddress.sin_addr.s_addr,
//					sizeof(clientAddress.sin_addr.s_addr),
//					PF_INET);
//
//			if(NULL == hostp)
//			{
//				/* error on get host address */
//			}
//
//			hostaddrp = inet_ntoa(clientAddress.sin_addr);
//			if(NULL == hostaddrp )
//			{
//				/* error on get inet_ntoa */
//			}
//
//
			/* Call server handler */
			server->Handler(&server->Config);

			/*
			  send the response to client
			 */
			server->Config.total_bytes_sent = sendto(socketServer,
					(uint8_t *)responseMsgBuffer,
					server->Config.total_bytes_to_send,
					0,
					(struct sockaddr *)&clientAddress,
					clientLen);
		}
	}
}





















