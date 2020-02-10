/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID-8
Write a program to REVERSE a given string using a Stack
*/
#include<stdio.h>
#include<string.h>
#define MAX 25

char stack[MAX],item;
int top=-1;

void push(char c)
{
	if(top == MAX-1)
		printf("\nArrayOutOfBoundException");
	else
	{
		top++;
		stack[top] = c;
	}
}

void display()
{
	int i;
	if(top == -1)
		printf("\nArrayOutOfBoundException");
	else
	{
		printf("\nReverse of the String is: ");
		for(i=top;i>=0;i--)
			printf("%c",stack[i]);
	}
}

int main()
{
	char input[MAX];
	int len,i;
	printf("-----====Reverse of the String using Stack====-----");
	printf("\nEnter your String: ");
	gets(input);
	len = strlen(input);
	for(i=0;i<len;i++)
	{
		push(input[i]);
	}
	display();
}
/*
-----====Reverse of the String using Stack====-----
Enter your String: Bilal Hungund

Reverse of the String is: dnugnuH laliB
--------------------------------*/
