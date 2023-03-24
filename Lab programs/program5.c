#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[20];
    int id;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
void insert_front(NODE head,char name1[20],int id)
{
    NODE temp;
    temp=getnode();
    temp->id=id;
    strcpy(temp->name,name1);
    if(head->link==NULL)
    {
        head->link=temp;
        temp->link=NULL;
        return;
    }
    NODE next=head->link;
    temp->link=next;
    head->link=temp;
    return;
}
void insert_rear(NODE head,char name[20],int id)
{
    NODE temp=getnode();
    strcpy(temp->name,name);
    temp->id=id;
    if(head->link==NULL)
    {
        head->link=temp;
        temp->link=NULL;
    }
    NODE perv;
    NODE cur=head->link;
    while(cur!=NULL)
    {
        perv=cur;
        cur=cur->link;
    }
    perv->link=temp;
    temp->link=NULL;
    return;
    
}
void delete_front(NODE head)
{
    if(head->link==NULL)
    {
        printf("empty");
        return;
    }
    NODE first=head->link;
    NODE second=first->link;
    printf("the deleted ele is %s %d",first->name[20],first->id);
    free(first);
    head->link=second;
}
void delete_rear(NODE head)
{
    if(head->link==NULL)
    {
        printf("empty");
        return;
    }
    NODE cur=head->link;
    NODE prev=NULL;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("the deleted node is %s %d",cur->name,cur->id);
    free(cur);
    prev->link=NULL;
}
void display(NODE head)
{
    //NODE prev;
    //printf("Enteted display");
    if(head->link==NULL)
    {
        printf("empty");
        return;
    }
    NODE cur;
    cur=head->link;
    //printf("Enterign the while loop");
    while(cur->link!=NULL)
    {
        printf("%s%d",cur->name,cur->id);
        cur=cur->link;
    }
    printf("%s %d",cur->name,cur->id);
    //printf("displayed");
}
int main()
{
    NODE head;
    head=getnode();
    head->link=NULL;
    int ele,ch,id;
    char name[20];
    while(1)
    {
        printf("1.insert_front 2.insert_rear 3.delete_front 4.delete_rear 5.display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   printf("enter the name and id");
                   scanf("%s%d",name,&id);
                   insert_front(head,name,id);
                   break;
            case 2:
                    printf("enter the name and id");
                   scanf("%s %d",&name,&id);
                   insert_rear(head,name,id);
                   break;
            case 3:
                    delete_front(head);
                   break;
            case 4:
                    delete_rear(head);
                   break;
            case 5:
                    display(head);
                    break;
            default:
                    exit(0);
        }
    }
}