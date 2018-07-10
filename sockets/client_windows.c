#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#pragma  comment(lib,"Ws2_32.lib")

#define bzero(a, b) memset(a, 0, b)
#define BUFFER_SIZE 1024

int main (int argc, const char * argv[])
{
	WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(1,1);
    err = WSAStartup(wVersionRequested,&wsaData);//加载Winsocket DLL
    if(err != 0){
        return 0;
    }

    if(LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1){
        WSACleanup();
        return 0;
    }

	struct SOCKADDR_IN server_addr;//服务器端口配置
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(11332);
    server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    bzero(&(server_addr.sin_zero),8);
  
	int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);//创建套接字
    if (server_sock_fd == -1) {
        perror("socket error");
        return 1;
    }
    char recv_msg[BUFFER_SIZE];
    char input_msg[BUFFER_SIZE];
    
    
    if (connect(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in))==0) {
        fd_set client_fd_set;

        tv.tv_sec = 20;
        tv.tv_usec = 0;
        
        while (1) {
            FD_ZERO(&client_fd_set);
            FD_SET(STDIN_FILENO, &client_fd_set);
            FD_SET(server_sock_fd, &client_fd_set);
            
            int ret = select(server_sock_fd + 1, &client_fd_set, NULL, NULL, &tv);
            if (ret < 0 ) {
                printf("select 出错!\n");
                continue;
            }else if(ret ==0){
                printf("select 超时!\n");
                continue;
            }else{
                if (FD_ISSET(STDIN_FILENO, &client_fd_set)) {
                    bzero(input_msg, BUFFER_SIZE);
                    fgets(input_msg, BUFFER_SIZE, stdin);
                    printf("asd\n");
                    if (send(server_sock_fd, input_msg, BUFFER_SIZE, 0) == -1) {
                        perror("发送消息出错!\n");
                    }
                }
                
                if (FD_ISSET(server_sock_fd, &client_fd_set)) {
                    bzero(recv_msg, BUFFER_SIZE);
                    long byte_num = recv(server_sock_fd,recv_msg,BUFFER_SIZE,0);
                    if (byte_num > 0) {
                        if (byte_num > BUFFER_SIZE) {
                            byte_num = BUFFER_SIZE;
                        }
                        recv_msg[byte_num] = '\0';
                        printf("服务器:%s\n",recv_msg);
                    }else if(byte_num < 0){
                        printf("接受消息出错!\n");
                    }else{
                        printf("服务器端退出!\n");
                        exit(0);
                    }           
                }
            }
        }
    }
    WSACleanup();
    return 0;
}
