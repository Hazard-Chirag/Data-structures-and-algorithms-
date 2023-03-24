/*Design, Develop and Implement a menu driven Program in C for the following Array
 Operations
 a. Creating an Array of N Integer Elements
 b. Display of Array Elements with Suitable Headings
 c. Exit.
 Support the program with functions for each of the above operations.*/ 

#include<stdio.h>
#include<stdlib.h>

void accept(int a[],int n)
{   printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
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
    int a[100],n,ch;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    accept(a,n);
    while(1)
    {
        printf("1-Display 2-Accept/create 3-exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: display(a,n);
                    break;
            case 2: accept(a,n);
                    break;
            default: exit(0);
        }
    }
    return 0;
    
}
