/*Design, Develop and Implement a menu driven Program in C for the following Array
 Operations
 a. Inserting an Element (ELEM) at a given valid Position (POS)
 b. Deleting an Element at a given valid Position POS)
 c. Display of Array Elements */

#include<stdio.h>
#include<stdlib.h>

void accept(int a[],int n)
{   printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void insert(int a[],int pos,int elem,int *n)
{
    if(pos>=0&&pos<(*n))
    {
        for(int i=(*n)-1;i>=pos;i--)
            a[i+1]=a[i];
        a[pos]=elem;
        printf("%d successfully inserted\n",a[pos]);
        (*n)++;
    }
    else
    printf("Insertion is not possible\n");
}
void delete(int a[],int pos,int *n)
{
    if(pos>=0 && pos<(*n))
    {   printf("%d is deleted\n",a[pos]);
        for(int i=pos;i<(*n)-1;i++)
            a[i]=a[i+1];
        (*n)--;
    }
    else
    printf("Deletion not possible\n");
}
void display(int a[],int n)
{
    if(n==0)
        printf("No elements to display\n");
    else
    {
        printf("Displaying array elements\n");
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");
    }   
}
int main()
{
    int a[100],n,pos,elem,ch;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    accept(a,n);
    while(1)
    {
        printf("1-Display 2-Insert 3-Delete 4-exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: display(a,n);
                    break;
            case 2: printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    printf("Enter the position to be inserted\n");
                    scanf("%d",&pos);
                    insert(a,pos,elem,&n);
                    break;
            case 3: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    delete(a,pos,&n);
                    break;
            default: exit(0);
        }
    }
    return 0;
    
}
