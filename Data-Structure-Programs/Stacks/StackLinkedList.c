/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID-7b
Write a menu driven program to implement STACK ADT using Linked List
and perform the following operations:
1. PUSH
2. POP
3. DISPLAY
4. PEEK
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top=NULL,*bottom=NULL;
int topI = -1;

struct stack* getNode()
{
	return ((struct stack *)malloc(sizeof(struct stack)));
}

int countStack()
{
	int count=0;
	struct stack *temp;
	temp = top;
	if(temp == NULL)
		return topI;
	else
	{
		while(temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
}
void push()
{
	int count;
	struct stack *newNode;
	newNode = getNode();
	count = countStack();
	printf("\nEnter your item: ");
	scanf("%d",&newNode->data);
	if(count == MAX)
		printf("\nStack Overflow Condition");
	else if(count == 0)
	{
		newNode->next = NULL;
		top = newNode;
		printf("\nItem Pushed: %d",newNode->data);
	}
	else
	{
		newNode->next = top;
		top = newNode;
		printf("\nItem Pushed: %d",newNode->data);
	}
}
void display()
{
	struct stack *temp;
	int count;
	temp = top;
	count = countStack();
	if(count == topI)
		printf("\nStack Underflow");
	else
	{
		printf("\nData in Stack is as follow: ");
		while(temp != NULL)
		{
			printf("\n%d",temp->data);
			temp = temp->next;	
		}
	}	
}
void peek()
{
	int count;
	count = countStack();
	if(count == topI)
		printf("\nStack Underflow");
	else
	{
		printf("\nData in Peek is: %d",top->data);	
	}
}
void pop()
{
	struct stack *temp = top;
	if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else
   {
      printf("\nDeleted element: %d", temp->data);
      top = temp->next;
      free(temp);
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
=>Enter your choice: 2

Deleted element: 5

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

Deleted element: 4

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 3

Data in Stack is as follow:
3
2
1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 4

Data in Peek is: 3

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Deleted element: 3

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Deleted element: 2

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Deleted element: 1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 2

Stack is Empty!!!


Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice: 3

Stack Underflow

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Push in Stack
2.) Pop in Stack
3.) Display Stack
4.) Show Peek of Stack
=>Enter your choice:
4

Stack Underflow

Do you want to continue? (1->Yes & Any number->NO): 0

Thanks for Coming
--------------------------------
*/
