#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int client();


int main() {
    client();
    return 0;
}

int client() {
	struct sockaddr_in serv_addr;
	int socketConn = 0;
    if((socketConn = socket(AF_INET, SOCK_STREAM, 0))< 0) {
       return 1;
    }
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(55556); 
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("Client is running!!!");
	if(connect(socketConn, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
       return 1;
    }
    FILE *fileptr;
    fileptr = fopen("received.txt", "w"); 
    if(NULL == fileptr){
        printf("File cannot be opened");
        return 1;
    }
	char bufferSize[128];
	int bytes = 0;
    while((bytes = read(socketConn, bufferSize, 128)) > 0){
        fwrite(bufferSize, 1,bytes,fileptr);
	    char receiving[bytes];
		}
	return 0;
}
