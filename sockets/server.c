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
#include <hiredis.h>

#define TRUE 1
#define FALSE 0
#define PORT 8888
#define PORT_find 4096
#define PORT_v6 2048
#define BACKLOG 2
#define MAX_EVENT 10
#define MAX_GROUP 10
#define MAX_MEMBER 10

int client_fds[MAX_EVENT];
int usertable[MAX_EVENT];
int grouptable[MAX_GROUP][MAX_MEMBER];
fd_set server_fd_set;

int option(char *buffer);
int login(char *username, int s);
int logout(char *username, int s);
int joingroup(char *groupname, int s);
int leavegroup(char *groupname, int s);
int savegroup();
int readgroup();
int sendmessage(char *callname, char* infor, int s);
void process_conn_server(int s);
void udp_server(char *buffer, int len, int s);

int option(char *buffer)
{
    int i, j, len;

    len = strlen(buffer);
    if( (len > 9) && (buffer[0] == 'l') && (buffer[1] == 'o')
       && (buffer[2] == 'g') && (buffer[3] == 'i') && (buffer[4] == 'n')
       && (buffer[5] == ' ')){
        for(i = 6; i < 11; i++){
            if((buffer[i] >= '0') && (buffer[i] < '9'))
                continue;
            else return 0;
        }
        return 1;
    }
    else if ((len > 10) && (buffer[0] == 'l') && (buffer[1] == 'o')
             && (buffer[2] == 'g') && (buffer[3] == 'o') && (buffer[4] == 'u')
             && (buffer[5] == 't') && (buffer[6] == ' ')){
        for(i = 7; i < 12; i++){
            if((buffer[i] >= '0') && (buffer[i] < '9'))
                continue;
            else return 0;
        }
        return 2;
    }
    else if ((len > 10) && (buffer[0] == 's') && (buffer[1] == 'e')
             && (buffer[2] == 'n') && (buffer[3] == 'd') && (buffer[4] == 't')
             && (buffer[5] == 'o') && (buffer[6] == ' ')){
        for(i = 7; i < 12; i++){
            if((buffer[i] >= '0') && (buffer[i] < '9'))
                continue;
            else return 0;
        }
        if (buffer[12] == ' ') return 3;
    }
    else if ((len > 8) && (buffer[0] == 'j') && (buffer[1] == 'o')
             && (buffer[2] == 'i') && (buffer[3] == 'n') && (buffer[4] == ' ')){
        for(i = 5; i < 10; i++){
            if((buffer[i] >= '0') && (buffer[i] < '9'))
                continue;
            else return 0;
        }
        return 4;
    }
    else if( (len > 9) && (buffer[0] == 'l') && (buffer[1] == 'e')
            && (buffer[2] == 'a') && (buffer[3] == 'v') && (buffer[4] == 'e')
            && (buffer[5] == ' ')){
        for(i = 6; i < 11; i++){
            if((buffer[i] >= '0') && (buffer[i] < '9'))
                continue;
            else return 0;
        }
        return 5;
    }
    return 0;
}

int login(char *username, int s)
{
    int i, id = 0, find = 0;
    
    char offline[1024];
    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c->err){
        redisFree(c);
        printf("Connect to redisServer faile\n");
        return 0;
    }
    redisReply *reply;
    reply = redisCommand(c,"GET %s", username);
    sprintf(offline, "%s", reply->str);
    if(offline[1] != 'n'){
        write(s, offline, strlen(offline));
        freeReplyObject(reply);
        reply = redisCommand(c,"SET %s (null)", username);
        freeReplyObject(reply);
    }
    
    id = atoi(username);
    for(i = 0; i < MAX_EVENT; i++){
        if(id == usertable[i]){
            find = 1;
            return 2;
        }
    }
    for(i = 0; i < MAX_GROUP; i++){
        if(id == grouptable[i][0]){
            find = 1;
            return 3;
        }
    }
    for(i = 0; i < MAX_EVENT; i++){
        if((s == client_fds[i]) && (usertable[i] == 0)){
            usertable[i] = id;
            return 1;
        }
    }
    return 0;
}

int logout(char *username, int s)
{
    int i, id = 0, find = 0;

    id = atoi(username);
    for(i = 0; i < MAX_EVENT; i++){
        if((s == client_fds[i]) && (usertable[i] == id)){
            usertable[i] = 0;
            return 1;
        }
    }
    return 0;
}

int sendmessage(char *callname, char* infor, int s)
{
    int dest, source;
    int i, j, k, id = 0, find = 0;
    char temp[1100];

    id = atoi(callname);
    
    for(i = 0; i < MAX_EVENT; i++){
        if(s == client_fds[i]){
            source = usertable[i];
        }
    }
    
    sprintf(temp, "FROM %d :\n%s\n", source, infor);
    for(i = 0; i < MAX_EVENT; i++){
        if(id == usertable[i]){
            dest = client_fds[i];
            if(dest){
                write(dest, temp, strlen(temp));
                return 1;
            }
        }
    }
    
    for(i = 0; i < MAX_GROUP; i++){
        if(id == grouptable[i][0]){
            for(j =1; j < MAX_MEMBER; j++){
                if(grouptable[i][j]){
                    for(k = 0; k < MAX_EVENT; k++){
                        if((grouptable[i][j] == usertable[k]) && (usertable[k] != source)){
                            memset(temp, 0, 1100);
                            sprintf(temp, "[group: %d]FROM %d :\n%s\n",grouptable[i][0], source, infor);
                            write(client_fds[k], temp, strlen(temp));
                        }
                    }
                }
            }
            return 2;
        }
    }
    
    char offline[1024];
    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c->err){
        redisFree(c);
        printf("Connect to redisServer faile\n");
        return 0;
    }
    
    redisReply *reply;
    reply = redisCommand(c,"GET %s", callname);
    printf("GET 724: %s\n", reply->str);
    sprintf(offline, "%s", reply->str);
    if(offline[1] == 'n') sprintf(offline, "\n(offline message)FROM %d :%s\n", source, infor);
    else sprintf(offline, "%s\n(offline message)FROM %d :%s\n", reply->str, source, infor);
    freeReplyObject(reply);
    
    reply = redisCommand(c,"SET %s %s", callname, offline);
    freeReplyObject(reply);
    
    return 0;
}

int joingroup(char *groupname, int s)
{
    int i, j, m, n, group_id = 0, find = 0, member_id;
    
    group_id = atoi(groupname);
    
    for(i = 0; i < MAX_EVENT; i++){
        if(s == client_fds[i]){
            member_id = usertable[i];
            if(!member_id) return -1;//用户不存在
            else if(member_id == group_id) return 0;
        }
    }

    for(i = 0; i < MAX_GROUP; i++){
        if(group_id == grouptable[i][0]){
            for(j =0; j < MAX_MEMBER; j++)
                if(member_id == grouptable[i][j]){
                    find = 1;
                    return 2;//已在组内
                }
            if(!find){
                for(j =0; j < MAX_MEMBER; j++)
                    if(grouptable[i][j] == 0){
                        find = 1;
                        grouptable[i][j] = member_id;
                        if(!savegroup()) printf("savegroup error!\n");
                        return 1;//成功添加
                    }
                if(!find) return 3;//组成员满
            }
        }
    }
    
    for(i = 0; i < MAX_GROUP; i++){
        if(grouptable[i][0] == 0){
            for(m = 0; m < MAX_GROUP; m++)
                for(n =1; n < MAX_MEMBER; n++)
                    if(grouptable[m][n] == group_id)
                        return 0;//组号与用户号重叠
            memset(grouptable[i], 0, MAX_MEMBER);
            grouptable[i][0] = group_id;
            grouptable[i][1] = member_id;
            if(!savegroup()) printf("savegroup error!\n");
            return 4;//新建组
        }
    }
    return 0;//组满
}

int leavegroup(char *groupname, int s)
{
    int i, j, group_id = 0, find = 0, member_id;
    
    group_id = atoi(groupname);
    
    for(i = 0; i < MAX_EVENT; i++){
        if(s == client_fds[i]){
            member_id = usertable[i];
        }
    }
    
    for(i = 0; i < MAX_GROUP; i++){
        if(group_id == grouptable[i][0]){
            for(j =0; j < MAX_MEMBER; j++)
                if(member_id == grouptable[i][j]){
                    find = 1;
                    grouptable[i][j] = 0;
                    if(!savegroup()) printf("savegroup error!\n");
                    return 1;//成功删除
                }
            if(!find) return 2;//不在组内
        }
    }
    return 0;//组号错误
}

int savegroup()
{
    char filename[] = "/Users/macx/Desktop/MY REVIEW/网络编程技术/homework3/group.txt";
    char id[5];
    FILE *fp = NULL;
    int i, j, k, temp = 0;
    
    memset(id, 0, 5);
    fp = fopen(filename, "r+");
    for(i = 0; i < MAX_GROUP; i++)
        for(j = 0; j < MAX_MEMBER; j++){
            memset(id, 0, 5);
            temp = grouptable[i][j];
            for(k = 0; k < 5; k++){
                id[k] = temp/pow(10, (4 - k)) + '0';
                temp = temp - (id[k] - '0') * pow(10, (4 - k));
            }
            if(j == (MAX_MEMBER - 1)) fprintf(fp, "%s\n", id);
            else fprintf(fp, "%s ", id);
    }
    fclose(fp);
    if((i == MAX_GROUP) && (j == MAX_MEMBER)) return 1;
    else return 0;
}

int readgroup()
{
    char filename[] = "/Users/macx/Desktop/MY REVIEW/网络编程技术/homework3/group.txt";
    char line[1024], id[5];
    FILE *fp = NULL;
    int group_i = 0, group_j =0, id_i = 0, line_i, len;
    
    memset(line, 0, 1024);
    memset(id, 0, 5);
    fp = fopen(filename, "r+");
    
    while(fgets(line, 1024, fp)){
        group_j = 0;
        len = strlen(line);
        for(line_i = 0; line_i < len; line_i++){
            if((line[line_i] == ' ') || (line[line_i] == '\n')){
                grouptable[group_i][group_j] = atoi(id);
                memset(id, 0, 5);
                id_i = 0;
                group_j++;
            }
            else{
                id[id_i] = line[line_i];
                id_i++;
            }
        }
        if(group_j > MAX_MEMBER) return 0;
        group_i++;
    }
    if(group_i > MAX_GROUP) return 0;
    fclose(fp);
    return 1;
}


void process_conn_server(int s)
{
    ssize_t size = 0;
    char buffer[1024], temp[1024], callname[20], username[5], groupname[5];
    int opt_function = 0, i, j, len = 0, opt_write = 0;

    memset(buffer, 0, strlen(buffer));
    memset(temp, 0, strlen(temp));
    memset(username, 0, 5);
    memset(callname, 0, 5);
    memset(groupname, 0, 5);

    if((size = read(s, buffer, 1024)) == 0){
        close(s);
        FD_CLR(s, &server_fd_set);
        for(i = 0; i < MAX_EVENT; i++){
            if(s == client_fds[i]){
                client_fds[i] = 0;
            }
        }
    }
    if(size > 0){
        len = 0;
        opt_function = option(buffer);
        len = strlen(buffer);
        if(opt_function == 1){
            for(i = len - 6, j = 0; i < (len - 1) ; i++, j++)
                username[j] = buffer[i];
            if(login(username, s) == 1){
                strcpy(temp, "login success!\n");
                write(s, temp, strlen(temp));
            }
            else  if(login(username, s) == 2){
                strcpy(temp, "Aleady online!\n");
                write(s, temp, strlen(temp));
            }
            else  if(login(username, s) == 3){
                strcpy(temp, "The ID is already used by the group!\n");
                write(s, temp, strlen(temp));
            }

            else{
                strcpy(temp, "login failure!\n");
                write(s, temp, strlen(temp));
            }
        }
        else if(opt_function == 2){
            for(i = len - 6, j = 0; i < len; i++, j++)
                username[j] = buffer[i];
            if(logout(username, s)){
                strcpy(temp, "logout success!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "logout failure!\n");
                write(s, temp, strlen(temp));
            }

        }
        else if(opt_function == 3){
            for(i = 7, j = 0; i < 12; i++, j++)
                callname[j] = buffer[i];
            for(i = 13, j = 0; i < len; i++, j++)
                temp[j] = buffer[i];
            opt_write = sendmessage(callname, temp, s);
            if(opt_write == 1){
                sprintf(temp, "send to the user %s successfully!\n", callname);
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                sprintf(temp, "send to the group %s successfully!\n", callname);
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "send failure(try to send offline message)!\n");
                write(s, temp, strlen(temp));
            }

        }
        else if(opt_function == 4){
            for(i = 5, j = 0; i < 10; i++, j++)
                groupname[j] = buffer[i];
            opt_write = joingroup(groupname, s);
            if(opt_write == 1){
                strcpy(temp, "join successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                strcpy(temp, "already in the group!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 3){
                strcpy(temp, "the group is full!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 4){
                strcpy(temp, "the group is not existed!\nfound the group successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == -1){
                strcpy(temp, "can not find the group!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "the group is not existed!\ncan not found the group!\n");
                write(s, temp, strlen(temp));
            }
        }
        else if(opt_function == 5){
            for(i = 6, j = 0; i < 11; i++, j++)
                groupname[j] = buffer[i];
            opt_write = leavegroup(groupname, s);
            if(opt_write == 1){
                strcpy(temp, "leave successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                strcpy(temp, "not in the group!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "the groupnumber is wrong!\n");
                write(s, temp, strlen(temp));
            }
        }
        else{
            strcpy(temp, "No such command!\n");
            write(s, temp, strlen(temp));
        }
    }
    if(!savegroup()) printf("savegroup error!\n");
}
/*
void udp_server(char *buffer, int len, int s)
{
    char temp[1024], callname[20], username[5], groupname[5];
    int opt_function = 0, i, j, opt_write = 0;
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(struct sockaddr);
    
    memset(temp, 0, strlen(temp));
    memset(username, 0, 5);
    memset(callname, 0, 5);
    memset(groupname, 0, 5);
    
    opt_function = option(buffer);
    
    if(opt_function == 1){
        for(i = len - 6, j = 0; i < len; i++, j++)
            username[j] = buffer[i];
            if(login(username, s) == 1){
                strcpy(temp, "login success!\n");
                //sendto(s, temp, len, 0, (struct sockaddr*)&client_addr, &addrlen);
            }
            else  if(login(username, s) == 2){
                strcpy(temp, "Aleady online!\n");
                write(s, temp, strlen(temp));
            }
            else  if(login(username, s) == 3){
                strcpy(temp, "The ID is already used by the group!\n");
                write(s, temp, strlen(temp));
            }
            
            else{
                strcpy(temp, "login failure!\n");
                write(s, temp, strlen(temp));
            }
        }
        else if(opt_function == 2){
            for(i = len - 6, j = 0; i < len; i++, j++)
                username[j] = buffer[i];
            if(logout(username, s)){
                strcpy(temp, "logout success!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "logout failure!\n");
                write(s, temp, strlen(temp));
            }
            
        }
        else if(opt_function == 3){
            for(i = 7, j = 0; i < 12; i++, j++)
                callname[j] = buffer[i];
            for(i = 13, j = 0; i < len; i++, j++)
                temp[j] = buffer[i];
            opt_write = sendmessage(callname, temp, s);
            if(opt_write == 1){
                sprintf(temp, "send to the user %s successfully!\n", callname);
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                sprintf(temp, "send to the group %s successfully!\n", callname);
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "send failure!\n");
                write(s, temp, strlen(temp));
            }
            
        }
        else if(opt_function == 4){
            for(i = 5, j = 0; i < 10; i++, j++)
                groupname[j] = buffer[i];
            opt_write = joingroup(groupname, s);
            if(opt_write == 1){
                strcpy(temp, "join successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                strcpy(temp, "already in the group!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 3){
                strcpy(temp, "the group is full!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 4){
                strcpy(temp, "the group is not existed!\nfound the group successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == -1){
                strcpy(temp, "can not find the user!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "the group is not existed!\ncan not found the group!\n");
                write(s, temp, strlen(temp));
            }
        }
        else if(opt_function == 5){
            for(i = 6, j = 0; i < 11; i++, j++)
                groupname[j] = buffer[i];
            opt_write = leavegroup(groupname, s);
            if(opt_write == 1){
                strcpy(temp, "leave successfully!\n");
                write(s, temp, strlen(temp));
            }
            else if(opt_write == 2){
                strcpy(temp, "not in the group!\n");
                write(s, temp, strlen(temp));
            }
            else{
                strcpy(temp, "the groupnumber is wrong!\n");
                write(s, temp, strlen(temp));
            }
        }
        else{
            strcpy(temp, "No such command!\n");
            write(s, temp, strlen(temp));

    if(!savegroup()) printf("savegroup error!\n");

}
*/

int main(int argc, char **argv)
{
    int s_T4, s_T6, s_U4, sc;
    int err;
    int bReuseaddr = TRUE;
    
    //设置
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    socklen_t addrlen = sizeof(struct sockaddr);
    
    /*
    struct sockaddr_in6 server_addr_v6;
    struct sockaddr_in6 client_addr;
    bzero(&server_addr_v6, sizeof(server_addr_v6));
    server_addr_v6.sin6_family = AF_INET6;
    server_addr_v6.sin6_addr = in6addr_any;
    server_addr_v6.sin6_port = htons(PORT);
    socklen_t addrlen = sizeof(struct sockaddr);
    //inet_pton(AF_INET6, "2001:470:1f01:f52b::2", &server_addr_v6.sin6_addr);
    */
    
    s_T4 = socket(AF_INET, SOCK_STREAM, 0);
    //s_T6 = socket(PF_INET6, SOCK_STREAM, 0);
    //s_U4 = socket(AF_INET, SOCK_DGRAM, 0);
    if(s_T4 < 0){
    //if(s_T6 < 0){
        printf("socket error!\n");
        return -1;
    }
    
    setsockopt(s_T4, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    err = bind(s_T4, (struct sockaddr*)&server_addr, sizeof(server_addr));
    //setsockopt(s_T6, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    //err = bind(s_T6, (struct sockaddr*)&server_addr_v6, sizeof(server_addr_v6));
    //setsockopt(s_U4, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    //err = bind(s_U4, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(err < 0){
        printf("bind error!\n");
        return -1;
    }
    
    setsockopt(s_T4, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    err = listen(s_T4, BACKLOG);
    //setsockopt(s_T6, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    //err = listen(s_T6, BACKLOG);
    if(err < 0){
        printf("listen error!\n");
        return -1;
    }
    
    //服务器自动发现
    /*
    struct sockaddr_in user_addr, test_addr;
    bzero(&user_addr, sizeof(user_addr));
    bzero(&test_addr, sizeof(test_addr));
    int on = 1, auto_find = 0;
    char IP_addr[20], IP_buffer[1024];
    socklen_t size;

    test_addr.sin_family = AF_INET;
    test_addr.sin_addr.s_addr=inet_addr("192.168.1.255");
    test_addr.sin_port = htons(PORT_find);
    
    user_addr.sin_family = AF_INET;
    user_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    user_addr.sin_port = htons(PORT_find);
    
    s_U4 = socket(AF_INET, SOCK_DGRAM, 0);
    if(s_U4 < 0){
        printf("socket error!\n");
        return -1;
    }
    setsockopt(s_U4, SOL_SOCKET, SO_BROADCAST, &on, sizeof(int));
    err = bind(s_U4, (struct sockaddr*)&user_addr, sizeof(user_addr));
    if(err < 0){
        printf("bind error!\n");
        return -1;
    }
    strcpy(IP_buffer,"find server IP test\n");
    sendto(s_U4, IP_buffer, strlen(IP_buffer), 0, (struct sockaddr*)&test_addr, sizeof(test_addr));
    size = sizeof(user_addr);
    recvfrom(s_U4, IP_buffer, 1024, 0, (struct sockaddr*)&user_addr, &size);
    strcpy(IP_addr,inet_ntoa(user_addr.sin_addr));
    //printf("my_ip:%s\n", IP_addr);
    test_addr.sin_addr.s_addr=inet_addr(IP_addr);
    setsockopt(s_U4, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuseaddr, sizeof(int));
    recvfrom(s_U4, IP_buffer, 1024, 0, (struct sockaddr*)&user_addr, &size);
    sendto(s_U4, IP_addr, strlen(IP_addr), 0, (struct sockaddr*)&user_addr, sizeof(test_addr));
    */
     
    //使用select
    int max_fd = -1;
    int i, len, index;
    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    char buffer[1024], temp[1024];
    
    memset(client_fds, 0, MAX_EVENT);
    memset(usertable, 0, MAX_EVENT);
    for(i = 0; i < MAX_GROUP; i++)
        memset(grouptable[i], 0, MAX_MEMBER);
    if(!readgroup()) printf("readgroup error!\n");

    while(1){
        //if(quit) return 1;
        FD_ZERO(&server_fd_set);
        FD_SET(s_T4, &server_fd_set);
        //FD_SET(s_T6, &server_fd_set);
        //FD_SET(s_U4, &server_fd_set);
        if(max_fd < s_T4) max_fd = s_T4;
        //if(max_fd < s_T6) max_fd = s_T6;
        //if(max_fd < s_U4) max_fd = s_U4;
        
        for(i = 0; i < MAX_EVENT; i++){
            if(client_fds[i] != 0){
                FD_SET(client_fds[i], &server_fd_set);
                if(max_fd < client_fds[i]) max_fd = client_fds[i];
            }
        }
        
        int ret = select(max_fd + 1, &server_fd_set, NULL, NULL, NULL);
        
        if(ret < 0){
            perror("select error!\n");
            continue;
        }
        else if(ret == 0){
            perror("select run out of time!\n");
        }
        else{
            //if(FD_ISSET(s_T6, &server_fd_set)){
            if(FD_ISSET(s_T4, &server_fd_set)){
                //sc = accept(s_T6, (struct sockaddr*)&client_addr, &addrlen);
                sc = accept(s_T4, (struct sockaddr*)&client_addr, &addrlen);
                index = -1;
                for(i =0; i < MAX_EVENT; i++){
                    if(client_fds[i] == 0){
                        index = i;
                        client_fds[i] = sc;
                        strcpy(temp, "succeed to link the server!\n");
                        write(sc, temp, strlen(temp));
                        break;
                    }
                }
                if(index < 0){
                    strcpy(temp, "fail to link the server!\n");
                    write(sc, temp, strlen(temp));
                }
            }
            for(i = 0; i < MAX_EVENT; i++){
                if(client_fds[i] != 0){
                    if(FD_ISSET(client_fds[i], &server_fd_set)){
                        process_conn_server(client_fds[i]);
                    }
                }
            }
            /*
            if(FD_ISSET(s_U4, &server_fd_set)){
                len = recvfrom(s_U4, temp, 1024, 0, (struct sockaddr*)&client_addr, &addrlen);
                udp_server(temp, len, s_U4);
            }
            */
        }
    }
}




