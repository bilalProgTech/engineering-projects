/*
Name 			: Hungund Bilal
Program Name	: ID - 13
Write a menu driven program to implement CIRCULAR QUEUE ADT using array and perform the following operation
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
*/
#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1,rear = -1;

void enqueue(int element)
{
	if(front == 0 && rear == MAX-1)
	{
		printf("\nQueue is Full");
	}
	else if(front == -1 && rear == -1)	//Adding Element in Empty queue
	{
		front = 0;
		rear = 0;
		queue[rear] = element;
		printf("Element Inserted: %d",element);
	}
	else if(rear == MAX-1 && front != 0)
	{
		rear = 0;			//Setting rear pointer to first loc
		queue[rear] = element;
		printf("Element Inserted: %d",element);
	}
	else
	{
		rear++;
		queue[rear] = element;
		printf("Element Inserted: %d",element);
	}
}

void display()
{
	int i;
	if(front == -1)
		printf("\nQueue is Empty");
	else
	{
		printf("\nElements in the queue: ");
		i = front;
		while(i!=rear)
		{
			printf("\n%d",queue[i]);
			if(i == MAX-1)
				i = 0;
			else
				i++;
		}
		printf("\n%d",queue[i]);
	}
}
void dequeue()
{
	int i;
	i = queue[front];
	if(front == -1)
		printf("\nQueue is Empty");
	else if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1)
		front = 0;
	else
		front++;
	printf("\nNumber Deleted: %d",i);
}
int main()
{
	int ch,input,element;
	printf("\n--------Welcome in Circular Queue Implementation--------");
	do
	{
		printf("\n1.) Enqueue in Queue");
		printf("\n2.) Dequeue in Queue");
		printf("\n3.) Display Queue");
		printf("\n=>Enter your choice: ");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("\nEnter Element to enqueue: ");
				scanf("%d",&element);
				enqueue(element);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("\nInvalid Choice");
		}
		printf("\n\nDo you want to continue? (1->Yes & Any number->NO): ");
		scanf("%d",&ch);
	}while(ch!=0);
	printf("\nThanks for Coming");
}
