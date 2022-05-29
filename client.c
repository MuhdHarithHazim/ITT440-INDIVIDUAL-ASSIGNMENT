#include <stdio.h>   //to printf()
#include <sys/socket.h> //to declare internet protocol family
#include <string.h> //header
#include<arpa/inet.h> //to declare inet address

#define PORT 8080

	int main(int argc, char *argv[])
	{
		int socket_desc;
		struct sockaddr_in server;
		char *message, server_reply[6000];
		
		//create a socket
		socket_desc = socket(AF_INET, SOCK_STREAM, 0);
		
		if (socket_desc == -1)
		{
			printf("Fail to create a socket");
		}
		server.sin_addr.s_addr = inet_addr("192.168.56.103");
			server.sin_family = AF_INET;
			server.sin_port = htons(PORT);
			
	//Connecting to remote server
		if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0)
			{
				puts("error connect");
				return 1;
			}
			puts("Connected Success \n");
			
	//Sending message
	message="connect";
	if( send(socket_desc, message, strlen(message, 0) <0)
		{
			puts("Message sending failed");
			return 1;
		}
		puts("Data Send \n");
		
	//Receiving message reply from server
		if(recv(socket_desc, server_reply, 6000, 0) < 0)
		{
			puts("Message received failed");
		}
		puts("Receive Successfully");
		puts(server_reply);
		return 0;
	}
