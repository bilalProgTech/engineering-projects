#include<stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int n)
{
	if(top == MAX-1)
		printf("\nStack Overflow");
	stack[++top] = n;
}
void main()
{
	int input,t,rem,i;
	printf("\nEnter Decimal Number: ");
	scanf("%d",&input);
	t = input;
	printf("\n");
	while(input>0)
	{
		rem = input % 8;
		input = input / 8;
		push(rem);
		printf("2 |\t %d \t| %d\n",input,rem);
	}
	printf("\n\nBinary Equivalent of %d is: ",t);
	for(i=top;i>=0;i--)
	{
		printf("%d",stack[i]);
	}
}
