#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<math.h>
#include<sys/errno.h>
#include<pthread.h>

#define BUFFER_SIZE 1024
#define PORT 8888

int client_num = 1000;
int linked_num = 0;

void * server_test(void * thread_num);
void * server_test(void * thread_num)
{
    struct sockaddr_in client_addr;
    bzero(&client_addr,sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htons(INADDR_ANY);
    client_addr.sin_port = htons(0);
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if( client_socket < 0){
        printf("Create Socket Failed!\n");
        exit(1);
    }
    if(bind(client_socket,(struct sockaddr*)&client_addr,sizeof(client_addr))){
        printf("Client Bind Port Failed!\n");
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.111");
    server_addr.sin_port = htons(PORT);
    socklen_t server_addr_length = sizeof(server_addr);
    if(connect(client_socket,(struct sockaddr*)&server_addr, server_addr_length) < 0){
        printf("Can Not Connect To Server!\n");
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    bzero(buffer,BUFFER_SIZE);
    int length = recv(client_socket,buffer,BUFFER_SIZE,0);
    if(length < 0){
        printf("Recieve Data From Server Failed!\n");
        exit(1);
    }
    printf("From Server: %s",buffer);
    linked_num++;
    close(client_socket);
    pthread_exit(NULL);

}

int main (int argc, char **argv)
{
    
    pthread_t child_thread;
    pthread_attr_t child_thread_attr;
    pthread_attr_init(&child_thread_attr);
    pthread_attr_setdetachstate(&child_thread_attr,PTHREAD_CREATE_DETACHED);
    
    int i = 0;
    for(i = 0; i < client_num; i++){
        if(pthread_create(&child_thread, &child_thread_attr, server_test, (void *)i) < 0)
            printf("pthread_create Failed : %s/n",strerror(errno));
    }
    printf("succcess link: %d\nfailure: %d\n", linked_num, (client_num - linked_num));
    return 0;
}
