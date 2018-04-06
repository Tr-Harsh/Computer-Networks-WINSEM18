#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{   
        struct sockaddr_in client,server;
    int s,n,no,i,j;
        char b1[100],b2[100];
        s=socket(AF_INET,SOCK_DGRAM,0);
        server.sin_family=AF_INET;
        server.sin_port=2003;
        server.sin_addr.s_addr=inet_addr("127.0.0.1");
        printf("\nClient ready....\n");
        n=sizeof(server);
        
printf("\nEnter number ofnodes: ");
	scanf("%s",&no);
        	printf("\nEnter matrix element row wise: \n");  
	for(i=0;i<no;i++)
        for(j=0;j<no;j++)
	{
			
		scanf("%s",&b2);
        	sendto(s,b2,sizeof(b2),0,(struct sockaddr *)&server,n);
	}          
	
        printf("\n\n**Message sent**\n");
}

