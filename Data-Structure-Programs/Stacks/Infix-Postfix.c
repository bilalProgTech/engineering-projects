/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID-11a
Write a program for conversion and evaluation of infix to POSTFIX notation
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int stack[MAX],top=-1;
int prece(char);
int calPostfix(char[]);
void push(int n)
{
	if(top == MAX-1)
		printf("\nStack Overflow");
	stack[++top] = n;
}
int pop()
{
	if(top == -1)
		printf("\nStack Underflow");
	return (stack[top--]);
}
void infixToPostfix(char expr[])
{
	int x=0,y=0,z,result=0;
	char a,c,postfix[MAX],t;
	push('\0');
	t = expr[x];
	while(t != '\0')
	{
		if(isalnum(t))
		{
			postfix[y] = t;
			y++;
		}
		else if(t == '(')
			push('(');
		else if(t == ')')
		{
			while(stack[top] != '(')
			{
				c = pop();
				postfix[y] = c;
				y++;
			}
			c = pop();
		}
		else
		{
			while(prece(stack[top])>=prece(t))
			{
				c = pop();
				postfix[y] = c;
				y++;
			}
			push(t);
		}
		x++;
		t = expr[x];
	}
	while(top != -1)
	{
		c = pop();
		postfix[y] = c;
		y++;
	}
	printf("\nThe Equivalent Postfix Expression: ");
	for(z=0;z<y;z++)
		printf("%c",postfix[z]);
	printf("\nDo you want to Evaulate this: (Y/N)");
	scanf("%c",&a);
	if(a=='y' || a=='Y')
	{
		result = calPostfix(postfix);
		printf("\nResult of your Expression is: %d",result);
	}
}

int calPostfix(char post[])
{
	int m,n,x,y,j=0,len;
	len = strlen(post);
	while(j<len)
	{
		if(isdigit(post[j]))
		{
			x = post[j]-'0';
			push(x);
		}
		else
		{
			m = pop();
			n = pop();
			switch(post[j])
			{
				case '+':
					x = n + m;
					break;
				case '-':
					x = n - m;
					break;
				case '*':
					x = n * m;
					break;
				case '/':
					x = n / m;
					break;	
			}
			push(x);
		}
		j++;
	}
	if(top>0)
	{
		printf("\nOperation Not done");
	}
	else
	{
		y = pop();
		return y;
	}
	return 0;
}
int prece(char t)
{
	switch(t)
	{
		case '+':
			return (7);
		case '-':
			return (7);
			break;
		case '*':
			return (8);
		case '/':
			return (8);
			break;
		case '\0':
			return (0);
			break;
		default:
			//printf("\nInvalid Expression");
			break;
	}
	return 0;
}
int main()
{
	char infix[MAX];
	printf("\nEnter your Expression: ");
	scanf("%s",&infix);
	infixToPostfix(infix);
}
/*
Enter your Expression: ((2*3)+(4*2))/2

The Equivalent Postfix Expression: 23*42*+2/
Do you want to Evaulate this: (Y/N)y

Result of your Expression is: 7
*/
