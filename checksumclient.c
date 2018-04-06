#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
int PORT=7981;
char sender[1024];
struct sockaddr_in addr;
int s = socket(AF_INET, SOCK_STREAM, 0);
if(s<0){
printf(" Socket not created\n");
}
else{
printf("Socket created\n");
}
addr.sin_port = htons(PORT);
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY);
int bind_var = bind(s, (struct sockaddr *)&addr,sizeof(struct
sockaddr_in) );
if(bind_var <0){
printf("Error binding socket\n");
}
else{
printf("Successfully bound to port %u\n", PORT);
}
int ls = listen(s,5);
if(ls<0){
printf("Listening Failed\n");}
else{
printf("Listening to socket \n");
}
int length = sizeof(struct sockaddr_in);
int accept_var = accept(s, (struct sockaddr *)&addr,&length);
if(accept_var == -1){
printf("Accept Failed\n");
}
else{
printf("Accepted the socket \n");
}
long sum=0;
int n, c, k, size, i, frame, l, m, o, y;
int j;
char msg[200];
for(y=0;y<5;y++){
j=0;
printf("Enter number of Frames\n");
scanf("%d",&frame);
for(i=0;i<frame;i++){
printf("Enter an integer in decimal number system and it's size\n");
scanf("%d%d", &n, &size);
for (c = size-1; c >= 0; c--){
k = n >> c;
if (k & 1)msg[j++]='1';
else
msg[j++]='0';
}
}
msg[32]='\0';
char *ptr;
long ret;
ret = strtol(msg, &ptr, 2);
//printf("RET - %ld",ret);
sum+=ret;
//printf("SUM - %ld",sum);
}
char temp;
for(y=0;y<2;y++){
j=0;
printf("Enter number of Frames\n");
scanf("%d",&frame);
for(i=0;i<frame;i++){
printf("Enter a alphabet and then enter the ASCII value\n");
scanf(" %c %d",&temp,&size);
int tem = (int)temp;
for (c = size-1; c >= 0; c--){
k = tem >> c;
if (k & 1)
msg[j++]='1';
else
msg[j++]='0';}
}
msg[32]='\0';
char *ptr;
long ret;
ret = strtol(msg, &ptr, 2);
sum+=ret;
}
printf("%ld\n",sum);
sprintf(sender,"%ld",sum);
send(accept_var , sender, 1024, 0);
}
