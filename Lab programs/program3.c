/*Design, Develop and Implement a menu driven Program in C for the following
 Operations on STACK of Integers (Array Implementation of Stack with
maximum size
 MAX)
 a. Push an Element on to Stack
 b. Pop an Element from Stack
 c. Demonstrate how Stack can be used to check Palindrome
 d. Demonstrate Overflow and Underflow situations on Stack
 e. Display the status of Stack
 f. Exit
 Support the program with appropriate functions for each of the above
operations. */

#include<stdio.h>
#include<stdlib.h>
#define m 10 
void push(int s[m],int *top,int elem)
{
	if((*top)==m-1)
	{
		printf("OVERFLOW");
		return;
	}
	else
	{
		(*top)++;
		s[*top]=elem;
	}
}
void pop(int s[m],int *top)
{
	int elem;
	if((*top)==-1)
	{
		printf("Underflow");
		return;
	}
	else
	{
		elem=s[*top];
		printf("%d is removed\n",elem);
		(*top)--;
	}
}
void display(int s[m],int top)
{
	for(int i=top;i>=0;i--)
	printf("%d\n",s[i]);
}

int palindrome(int s[],int *top)
{
        int temp[m], i, j, count=0;
        for(j=0; (*top)>=0; j++)
        {
        temp[j]= stack[(*top)--];
        count+=1;
        }
        for(i=0; i<=count/2; i++)
        {
        if( temp[i]!=temp[count-i-1])
        return -1;
        }
        return 1;
}
int main()
{
	int s[m],top,elem,choice,flag;
	top=-1;
	while(1)
	{
		printf("ENter 1 for push,2-pop,3-display,4-palindrome,5-exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("ENter element\n");
				    scanf("%d",&elem);
			    	push(s,&top,elem);
				    break;
			case 2:	pop(s,&top);
				    break;
			case 3: printf("DIsplaying stack\n");
				    display(s,top);
				    break;
            case 4: flag=palindrome(s,&top);
                    if(flag==-1)
                         printf("Not a palindrome.\n");
                    else
                        printf("Palindrome.\n");
                    break;
			default: exit(0);
		}
	}
	return 0;
}
