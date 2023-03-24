/*Design, Develop and Implement a Program in C for the following Stack applications
 a. Evaluation of Suffix expression with single digit operands and operators:
 +, -, *, /, %, ^ */


#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define m 20
int compute(int op1,char operator,int op2)
{
	switch(operator)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '%': return op1%op2;
		case '$':
		case '^': return pow(op1,op2);
	}
}
void push(int s[m],int *top,int elem)
{
	(*top)++;
	s[*top]=elem;
}
int pop(int s[m],int *top)
{
	return s[(*top)--];
}
int eval_post(char postfix[20])
{
	int i,s[m],top=-1,op1,op2,res;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		push(s,&top,postfix[i]-'0');
		else
		{
			op2=pop(s,&top);
			op1=pop(s,&top);
			res=compute(op1,postfix[i],op2);
			push(s,&top,res);
		}
	}
	return pop(s,&top);
}
int main()
{
	char postfix[20];
	int res;
	printf("ENter the postfix expression\n");
	scanf("%s",postfix);
	res=eval_post(postfix);
	printf("Result is = %d\n",res);
	return 0;
}

			
