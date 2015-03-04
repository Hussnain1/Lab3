#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int server();

int main() {
   server();
   return 0;
}

int server() {
	struct sockaddr_in serv_addr;
	int listen = 0;
    int connection = 0;
    
    listen = socket(AF_INET, SOCK_STREAM, 0);
    printf("Server is up!!!\n");
	char bufferSize[1024];
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(bufferSize, '0', sizeof(bufferSize));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(55556);

    bind(listen, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

    if(listen(listen, 10) == -1){
        return -1;
    }


    while(1)
    {
        connection = accept(listen, (struct sockaddr*)NULL ,NULL);

        FILE *fileptr = fopen("transfer.txt","rb");
        if(fileptr==NULL){
            printf("Cannot open file!!!!");
            return 1;   
        }   

       
        while(1) {
            unsigned char readbuffer[128]={0};
            int readbytes = fread(readbuffer,1,128,fileptr);
                     
            if(readbytes > 0){
                printf("Sending file to server\n");
                write(connection, readbuffer, readbytes);
            }

           
            if (readbytes < 128){
                if (feof(fileptr))
                    printf("End of file!!!\n");
                if (ferror(fileptr))
                    printf("There is some error in reading the file!!!!\n");
                break;
            }


        }

        close(connection);
        sleep(1);
    }


    return 0;
}
