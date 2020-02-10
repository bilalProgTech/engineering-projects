/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID-10
Write a program to implement PARENTHESES CHECKER using a stack 
*/
#include <stdio.h>
#define max 50

void main()
{
	char stack[max],exp[100];
	int top=-1,i;
	printf("-----====Parenthesis Checker using Stack====-----");
	printf("\nEnter your Expression: ");
	gets(exp);	
	for(i=0; exp[i] != '\0'; i++)
	{
		if( exp[i]=='(' || exp[i] =='[' || exp[i] == '{' )
		{
			top++;
			stack[top]= exp[i];
		}
		else if(exp[i] == ')')
		{
			if(stack[top] == '(')
				top--;
			else
			{
				printf("\n() <- Missing");
			}
		}
		else if(exp[i] == ']')
		{
			if(stack[top] == '[')
				top--;
			else
			{
				printf("\n[] <- Missing");
			}
		}
		else if(exp[i] == '}')
		{
			if(stack[top] == '{')
				top--;
			else
			{
				printf("\n{} <- Missing");	
			}
		}
	}
	if( top == -1 )
		printf("\nExpression is balanced");
	else
		printf("\nExpression is not balanced");
}
/*
-----====Parenthesis Checker using Stack====-----
Enter your Expression: {[(A+B)-(N+o)]*[(A-d)-(A-k)]}

Expression is balanced

-----====Parenthesis Checker using Stack====-----
Enter your Expression: (Ah)-[j-k;

Expression is not balanced

-----====Parenthesis Checker using Stack====-----
Enter your Expression: {{{{{}}}

Expression is not balanced
--------------------------------

*/
