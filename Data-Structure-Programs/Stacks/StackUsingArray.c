/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID-7a
Write a menu driven program to implement STACK ADT using array 
and perform the following operations:
1. PUSH
2. POP
3. DISPLAY
4. PEEK
*/
#include<stdio.h>
#define MAX 10

int stack[MAX],item,top=-1;

void push()
{
	if(top == MAX-1)
		printf("\nStack Overflow Conition");
	else
	{
		printf("\nEnter your item: ");
		scanf("%d",&item);
		top++;
		stack[top] = item;
		printf("\nItem Pushed: %d",item);	
	}	
}

void pop()
{
	if(top == -1)
		printf("\nStack Underflow Condition");
	else
	{
		item = stack[top];
		top--;
		printf("\nItem Popped: %d",item);
	}
}

void display()
{
	int i;
	if(top == -1)
		printf("\nStack Underflow Condition");
	else
	{
		printf("\nData in Stack is as follow: ");
		for(i=top;i>=0;i--)
			printf("\n%d",stack[i]);
	}
}

void peek()
{
	if(top == -1)
		printf("\nStack Underflow Condition");
	else
	{
		printf("\nData in Peek is: %d",stack[top]);
	}
}

int main()
{
	int ch,input;
	printf("\n--------Welcome in Stack Implementation--------");
	do
	{
		printf("\n1.) Push in Stack");
		printf("\n2.) Pop in Stack");
		printf("\n3.) Display Stack");
		printf("\n4.) Show Peek of Stack");
		printf("\n=>Enter your choice: ");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			default:
				printf("\nInvalid Choice");
		}
		printf("\n\nDo you want to continue? (1->Yes & Any number->NO): ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("\nThanks for Coming");
}
/*
Output:

--------Welcome in Stack Implementation--------
1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Stack Underflow Condition

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 3

Stack Underflow Condition

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 4

Stack Underflow Condition

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 1

Enter your item: 1

Item Pushed: 1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 1

Enter your item: 2

Item Pushed: 2

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 1

Enter your item: 3

Item Pushed: 3

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 1

Enter your item: 4

Item Pushed: 4

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 1

Enter your item: 5

Item Pushed: 5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 3

Data in Stack is as follow:
5
4
3
2
1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 4

Data in Peek is: 5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Item Popped: 5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 3

Data in Stack is as follow:
4
3
2
1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 4

Data in Peek is: 4

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Item Popped: 4

Do you want to continue? (1->Yes & Any number->NO): 2

Thanks for Coming
*/
