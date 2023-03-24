/*Design, Develop and implement a program in C for the following operations on Graph (G) of
cities
 a. Create a Graph of N cities using Adjacency Matrix.
 b. Print all the nodes reachable from a given starting node in a diagraph using DFS/BFS
 method.
 */

#include<stdio.h>
#include<stdlib.h>

int a[10][10],F[10];

void read_adj(int n)
{
    int i,j;
    printf("Enter adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
}

void dfs(int u,int n)
{
    int top=-1,v;
    int s[10];//stack
    printf("\nCities reachable from %d: ",u);
    s[++top]=u;//push
    F[u]=1;
    printf("%d\t",u);
    while(top!=-1)//until stack empty
    {
        u=s[top--];
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1 && F[v]==0)
            {
                printf("%d\t",v);
                F[v]=1;//set flag
                s[++top]=v;//push to stack
            }
        }
    }
}

void bfs(int u,int n)
{
    int rear=-1,front=0,v;
    int q[10];//queue
    printf("\nCities reachable from %d: ",u);
    q[++rear]=u;//insert
    F[u]=1;
    printf("%d\t",u);
    while(front<=rear)//until queue empty
    {
        u=q[front++];//delete front
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1 && F[v]==0)
            {
                printf("%d\t",v);
                F[v]=1;//set flag
                q[++rear]=v;//insert in queue
            }
        }
    }
}

void dfs_recursive(int u,int n)
{
    int v;
    printf("%d",u);
    F[u]=1;;
    for(v=0;v<n;v++)
    {
        if(a[u][v]==1 && F[v]==0)
            dfs_recursive(v,n);
    }
}
int main()
{
    int i,source,n;
    printf("Enter no of cities\n");
    scanf("%d",&n);
    read_adj(n);
    for(source=0;source<n;source++)
    {
        for(i=0;i<n;i++)
            F[i]=0; //setting all flags to 0 initially(cuz not traversed)     
        dfs(source,n);
    }
    return 0;

}
