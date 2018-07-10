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

#define BUFFER_SIZE 1024
#define PORT 8888
#define PORT_find 4096
#define PORT_v6 2048
#define TRUE 1
#define FALSE 0

int main (int argc, char **argv)
{
    
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.111");
    bzero(&(server_addr.sin_zero),8);

    /*
    struct sockaddr_in6 server_addr_v6;
    bzero(&server_addr_v6,sizeof(server_addr_v6));
    server_addr_v6.sin6_family = AF_INET6;
    server_addr_v6.sin6_port = htons(PORT);
    
    if(inet_pton(AF_INET6, "2001:470:1f01:f52b::2", &server_addr_v6.sin6_addr) < 0){
        perror("inet_pton error");
        return 1;
    }
    */
    
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    //int server_sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    //int server_sock_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (server_sock_fd < 0) {
        perror("socket error");
        return 1;
    }
    
    //服务器自动发现
    /*
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT_find);
    socklen_t size;
    char IP_addr[20], IP_buffer[1024];
    int auto_find = 0, i;
    int find_server_sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (find_server_sock_fd < 0) {
        perror("socket error");
        return 1;
    }
    size = sizeof(server_addr);
    strcpy(IP_buffer, "get IP_addr\n");
    while(!auto_find){
        sendto(find_server_sock_fd, IP_buffer, strlen(IP_buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        recvfrom(find_server_sock_fd, IP_buffer, 1024, 0, (struct sockaddr*)&server_addr, &size);
        if(IP_buffer[0] == '1'){
            auto_find = 1;
            for(i = 0; ((IP_buffer[i] <= '9') && (IP_buffer[i] >= '0')) || (IP_buffer[i] == '.');i++)
                IP_addr[i] = IP_buffer[i];
        }
    }
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP_addr);
    */
    
    char recv_msg[BUFFER_SIZE];
    char input_msg[BUFFER_SIZE];
    int byte_num;
    memset(recv_msg, 0, BUFFER_SIZE);
    memset(input_msg, 0, BUFFER_SIZE);
    
    //if(connect(server_sock_fd, (struct sockaddr*)&server_addr_v6, sizeof(struct sockaddr_in6)) != -1){
    if(connect(server_sock_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == 0){
    //if(auto_find){
        fd_set client_fd_set;
        struct timeval tv;
        tv.tv_sec = 20;
        tv.tv_usec = 0;
        
        while(1){
            FD_ZERO(&client_fd_set);
            FD_SET(STDIN_FILENO, &client_fd_set);
            FD_SET(server_sock_fd, &client_fd_set);
            
            int ret = select(server_sock_fd + 1, &client_fd_set, NULL, NULL, NULL);
            if(ret < 0){
                printf("select error!\n");
                continue;
            }
            else if(ret ==0){
                perror("select run out of time!\n");
                continue;
            }
            else{
                if (FD_ISSET(STDIN_FILENO, &client_fd_set)) {
                    bzero(input_msg, BUFFER_SIZE);
                    fgets(input_msg, BUFFER_SIZE, stdin);
                    if(send(server_sock_fd, input_msg, BUFFER_SIZE, 0) == -1){
                        perror("send error!\n");
                    }
                }
                if (FD_ISSET(server_sock_fd, &client_fd_set)) {
                    bzero(recv_msg, BUFFER_SIZE);
                    byte_num = recv(server_sock_fd,recv_msg,BUFFER_SIZE,0);
                    if (byte_num > 0) {
                        if (byte_num > BUFFER_SIZE) {
                            byte_num = BUFFER_SIZE;
                        }
                        recv_msg[byte_num] = '\0';
                        printf("server:%s\n",recv_msg);
                    }
                    else if(byte_num < 0){
                        printf("receive error!\n");
                    }
                    else{
                        printf("server logout!\n");
                        exit(0);
                    }
                }
            }
        }
    }
    
    return 0;
}

