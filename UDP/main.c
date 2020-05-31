/*
 ============================================================================
 Name        : main.c
 Author      : Mido
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"
#include "udp.h"



void clientTest();
void serverTest();

void serverHandler();



int main(void)
{
	printf("Starting...\n");
	fflush(stdout);

	clientTest();
//	serverTest();

	printf("\nEnd of main.\n");
	fflush(stdout);
	return 0;
}

void serverTest()
{
	UDP_Server server;

	server.Config.ip 	= "192.168.1.5";
	server.Config.port 	= 5000;
	server.Handler = serverHandler;

	Server_Lunch(&server);
}


void serverHandler(Server_Config_t *server)
{
	int i = 0;
	for(i = 0; i < server->total_bytes_received; ++i)
	{
		printf("\nRequest Received: %c", server->recv_msg[i]);
	}

	char msg[37] = "7ases b twator w el amn m4 mostateb";

	server->total_bytes_to_send = 37;

	for(i = 0; i < 37; ++i)
	{
		server->sent_msg[i] = msg[i];
	}

}


void clientTest()
{
	uint8_t recBuff[MAX_LINE];

	UDP_Client client = {
			.ip 				= "192.168.1.5",
			.port 				= 5000,
			.request_msg		= (uint8_t *)"Client by2ol saba7 el 5ara 3ala dma8ak",
			.request_msg_size 	= 38,
			.response_msg		= recBuff,
			.timeout			= 3,	// in seconds
			.wait_for_response 	= OK
	};


	Client_Request(&client);
	printf("%d bytes received.\n", client.total_bytes_received);
	fflush(stdout);
	for(int i = 0; i < client.total_bytes_received; ++i)
	{
		printf("%c ", client.response_msg[i]);
		fflush(stdout);
	}
	printf("\n");

}


