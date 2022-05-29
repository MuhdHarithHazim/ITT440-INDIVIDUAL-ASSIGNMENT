#include <stdio.h>   //to printf()
#include <unistd.h>  //to declare functions
#include <stdlib.h>  //to declare variables
#include <sys/socket.h> //to declare internet protocol family
#include <netinet/in.h> //to declare internet address family
#include <string.h> //header

#define PORT 8080
int main (int argc, char const *argv[])
{
	int server_fd, new_socket;
	long valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	
	//HTTP rotocol
	char *hello = HTTP/1.1 200 OK\nContent-Type:
	text/plain\nContent-Length: 50\n\n Hazim's Individual Assignment";
	
	//creating socket file
	if ((server_fd = socket (AF_INET, SOCK_STREAM, 0)) == 0)
		{
			perror("In socket");
			exit(EXIT_FAILURE);
		}
		
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(PORT);
		
		memset(address.sin_zero, '\0', sizeof address.sin_zero);
		
		//bind
		if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) <0)
		{
			perror("In bind");
			exit(EXIT_FAILURE);
		}
		//listen
		if (listen(server_fd, 10) < 0)
		{
			perror("In listen");
			exit(EXIT_FAILURE);
		}
		while(1)
		{
			printf("\nRECEIVED HTTP RESPONSE \n");
			if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
			{
            perror("In accept");
			exit(EXIT_FAILURE);
			}
        
			char buffer[50000] = {0};
			valread = read( new_socket , buffer, 50000);
			printf("%s\n",buffer );
			write(new_socket , hello , strlen(hello));
			printf("RESPONSE RECEIVED FROM SERVER");
			close(new_socket);
		}
		return 0;
}
