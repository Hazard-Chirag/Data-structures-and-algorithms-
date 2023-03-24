#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink,*rlink;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE x;
    x=(NODE) malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    return x;
}

NODE insert_BST(NODE root,int info)
{
    NODE temp;
    temp=getnode();
    temp->llink=NULL;
    temp->rlink=NULL;
    temp->info=info;
    if(root==NULL)
        return temp;
    NODE cur=root,prev=NULL;
    while (cur!=NULL)
    {
        prev=cur;
        if((cur->info)>info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }//prev has address of last node where we need to insert
    if((prev->info)<info)
        prev->rlink=temp;
    else
        prev->llink=temp;
    
    return root;
    
}

void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if(root==NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\n",root->info);
}

void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d\n",root->info);
    inorder(root->rlink);
}

int main()
{
    NODE root=NULL;
    int n,item,i;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element\n");
        scanf("%d",&item);
        root=insert_BST(root,item);
    }
    printf("Displaying elements\n");
    int ch;
    while (1)
    {
        printf("1-preorder,2-postorder,3-inorder,4-exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: preorder(root);
                break;
        case 2: postorder(root);
                break;
        case 3: inorder(root);
                break;
        default: exit(0);
        }
    }
    return 0;
}