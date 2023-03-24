#include<stdio.h>
#include<stdlib.h>
#define HZ 3
typedef
struct Employee
{
    char name[20];
    int id;
    int sal;
}Emp;

typedef
struct hashtable
{
    int key;
    long int addr;
}ht;

int hashval(int empno)
{
    return empno%HZ;
}

void insert(FILE *fp,ht *h,int n)
{
    Emp a;
    int i,hindex,countindex;
    for(i=0;i<n;i++)
    {
        printf("Enter employee name,id,sal\n");
        scanf("%s%d%d",a.name,&(a.id),&(a.sal));
        hindex=countindex=hashval(a.id);
        while(h[hindex].key!=-1)
        {
            hindex=(hindex+1)%HZ;
            if(hindex==countindex)
            {
                printf("Insertion not possible\n");
                return;
            }
        }
        h[hindex].key=a.id;
        fseek(fp,0,SEEK_END);
        h[hindex].addr=ftell(fp);
        fwrite(&a,sizeof(Emp),1,fp);
        printf("%s%d%d%ld",a.name,a.id,a.sal,h[hindex].addr);
    }
}
void display(FILE *fp,ht *h)
{
    Emp a;
    for(int i=0;i<HZ;i++)
    {
        if(h[i].key!=-1)
        {
            fseek(fp,h[i].addr,SEEK_SET);
            fread(&a,sizeof(Emp),1,fp);
            printf("%s%d%d%ld",a.name,a.id,a.sal,h[i].addr);
        }
    }
}

int main()
{
    Emp a;
    FILE *fp;
    ht h[HZ];
    int i,n,ch;
    while (1)
    {
        printf("Enter 1-insert,2-display,3-exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("ENTER NUMBER OF ELEMENTS\n");
                scanf("%d",&n);
                for(int i=0;i<HZ;i++)
                    h[i].key=-1;
                fp=fopen("nayi.txt","w");
                insert(fp,h,n);
                fclose(fp);
                break;
        case 2: fp=fopen("nayi.txt","r");
                display(fp,h);
                break;
        default:
            exit(0);
        }
    }
    
}