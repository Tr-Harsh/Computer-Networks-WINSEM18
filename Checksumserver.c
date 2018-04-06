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
addr.sin_port = htons(PORT);addr.sin_family = AF_INET;
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
printf("Listening Failed\n");
}
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
}int j=0;
int remainder=0;
recv(accept_var , sender, 1024, 0);
char *ptr;
long seme;
seme = strtol(sender,&ptr,10);
char prin[32];
for (j = 31; j>=0; j--){
remainder = seme%2;
if(remainder==1)
prin[j] = '1';
else
prin[j] = '0';
seme=seme/2;
}
prin[32]='\0';
printf("Client : Data Received (Checksum) - %s",prin);
printf("\n");
}
