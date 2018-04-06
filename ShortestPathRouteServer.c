#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define INFINITY 9999
void dijkstra(long G[10][10],int n,int startnode);

int main()
{
struct sockaddr_in cliaddr,myaddr;
int servsock,clisock;
long G[10][10];
char b1[100],b2[100];
servsock=socket(AF_INET,SOCK_DGRAM,0);
myaddr.sin_family=AF_INET;
myaddr.sin_port=2003;
myaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(servsock,(struct sockaddr *)&myaddr,sizeof(myaddr));
printf("\nServer ready,waiting for client....\n");
clisock=sizeof(cliaddr);
int n=3,u,i,j;
char *ptr;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
recvfrom(servsock,b1,sizeof(b1),0,(struct sockaddr *) &cliaddr,&clisock);
printf("\n%d th row and %d th column element is %s",i+1,j+1,b1);
G[i][j]=strtol(b1,&ptr,10);	
}

printf("\nEnter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}


void dijkstra(long G[10][10],int n,int startnode)
{
 
    int cost[10][10],distance[10],pred[10];
    int visited[10],count,mindistance,nextnode,i,j;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
     for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);
            
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
    }
}
