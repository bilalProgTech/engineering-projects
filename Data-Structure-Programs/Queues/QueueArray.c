/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 12a
Write a menu driven program to implement QUEUE ADT using array and perform the following operation
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
*/
#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element)
{
	if(rear == MAX_SIZE)
		printf("\nQueue is Full");
	else if(front == -1)
	{
		front++;
		rear++;
		queue[front] = element;
		printf("Element Inserted: %d",element);
	}
	else
	{
		rear++;
		queue[rear] = element;
		printf("Element Inserted: %d",element);
	}
}

void dequeue()
{
	int elem;
	if(front == -1 && rear == -1)
		printf("\nQueue is Empty");
	else if(front != -1 && front == rear)
	{
		elem = queue[front];
		front = -1;
		rear = -1;
		printf("Element Deleted: %d",elem);
	}
	else
	{
		elem = queue[front];
		front++;
		printf("Element Deleted: %d",elem);
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
		for(i=front;i<=rear;i++)
			printf("\n%d",queue[i]);
	}
}
int main()
{
	int ch,input,element;
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
