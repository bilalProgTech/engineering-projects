/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 12b
Write a menu driven program to implement QUEUE ADT using linked list and perform the following operation
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct queue
{
	int element;
	struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

struct queue* getNode()
{
	return ((struct queue *)malloc(sizeof(struct queue)));
}

void enqueue()
{
	struct queue *newNode;
	newNode = getNode();
	printf("\nEnter element to enqueue: ");
	scanf("%d",&newNode->element);
	if(front == NULL)
	{
		newNode->next = NULL;
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode;
		newNode->next = NULL;
		rear = newNode;
	}
	printf("Element Inserted: %d",newNode->element);
}

void dequeue()
{
	int elem;
	struct queue *ptr;
	if(front == NULL)
		printf("\nQueue is Empty");
	else
	{
		elem = front->element;
		ptr = front;
		front = front->next;
		free(ptr);
		printf("\nElement Deleted: %d",elem);
	}
}

void display()
{
	struct queue *temp;
	temp = front;
	if(front == NULL)
		printf("\nQueue is Empty");
	else
	{
		printf("\nElements in the queue: ");
		while(temp != NULL)
		{
			printf("\n%d",temp->element);
			temp = temp->next;
		}
		//printf("\n%d",rear->element);
	}
}
int main()
{
	int ch,input;
	printf("\n--------Welcome in Queue Implementation--------");
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
				enqueue();
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
/*

--------Welcome in Queue Implementation--------
1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Queue is Empty

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Queue is Empty

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 1
Element Inserted: 1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 2
Element Inserted: 2

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 3
Element Inserted: 3

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 4
Element Inserted: 4

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 5
Element Inserted: 5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
1
2
3
4
5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 1

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
2
3
4
5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 2

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 3

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
4
5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 4

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 1

Enter element to enqueue: 8
Element Inserted: 8

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
5
8

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Elements in the queue:
5
8

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 5

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 2

Element Deleted: 8

Do you want to continue? (1->Yes & Any number->NO): 1

1.) Enqueue in Queue
2.) Dequeue in Queue
3.) Display Queue
=>Enter your choice: 3

Queue is Empty

Do you want to continue? (1->Yes & Any number->NO): 0

Thanks for Coming
--------------------------------
*/
