/*
Name		: Hungund Bilal
Roll No.	: IT-68
Write a menu driven program to implement list ADT using DOUBLY LINK LIST and perform the following operations
1.) CREATE				2.) INSERT AT BEGINNING
3.) INSERT AT END			4.) INSERT AT LOCATION
5.) DELETE AT BEGINNING			6.) DELETE AT END
7.) DELETE AT LOCATION			8.) DISPLAY
9.) SEARCH				10.)COUNT
11.)COPY 				12.)CONCATENTE
13.)SPLIT				14.)REVERSE
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL,*copy = NULL,*split = NULL;

struct node* getNode()
{
	return ((struct node *)malloc(sizeof(struct node)));
}

void createList()
{
	struct node *newNode,*temp;
	int input,i;
	printf("\nEnter how many nodes you want: ");
	scanf("%d",&input);
	for(i=1;i<=input;i++)
	{
		newNode = getNode();
		printf("\nEnter data for %d Node: ",i);
		scanf("%d",&newNode->data);
		if(i==1)
		{
			start = newNode;
			newNode->prev = NULL;
			newNode->next = NULL;
		}
		else
		{
			temp = start;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
		}
	}
}
void displayListWithAddress(struct node *temp)
{
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else
	{
		while(temp != NULL)
		{
			printf("Temp: %d [%d | %d | %d]\n",temp,temp->prev,temp->data,temp->next);
			temp = temp->next;
		}
	}
}
void displayList(struct node *temp)
{
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else
	{
		while(temp != NULL)
		{
			printf("\nData: %d",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void reverseList(struct node *temp)
{
	if(temp->next == NULL) 
	{
		printf("\nData: %d",temp->data);
		return;
	}
	reverseList(temp->next);
	printf("\nData: %d",temp->data);
}
void insertAtBeginning()
{
	struct node *newNode;
	newNode = getNode();
	printf("Enter data for new Node: ");
	scanf("%d",&newNode->data);
	start->prev = newNode;
	newNode->next = start;
	start = newNode;
	newNode->prev = NULL;
}
void insertAtLocation()
{
	struct node *temp,*newNode;
	int i,count=0,loc;
	newNode = getNode();
	temp = start;
	if(temp == NULL)
		printf("\nList is empty can't Possible");
	else
	{
		count = countList(start);
		printf("\nEnter Data to Insert: ");
		scanf("%d",&newNode->data);
		printf("\nEnter Location on which you want to insert: ");
		scanf("%d",&loc);
		if(loc > count)
			printf("\nYou can't perform insertion at that Location'");
		else
		{
			for(i=1;i<loc-1;i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			(temp->next)->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		}
	}	
}
int countList(struct node *temp)
{
	int count = 0;
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else
	{
		while(temp != NULL)
		{
			temp = temp->next;
			count++;
		}
	}
	return count;
}
void insertAtEnd()
{
	struct node *temp;
	struct node *newNode;
	newNode = getNode();
	temp = start;
	if(temp == NULL)
		printf("\nLinked List is Null");
	else
	{
		printf("\nEnter Data for new node: ");
		scanf("%d",&newNode->data);
		newNode->next = NULL;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}
void deleteAtBeginning()
{
	struct node *temp;
	temp = start;
	if(temp == NULL)
	{
		if(temp->next == NULL)
			free(temp);
		else
			printf("Linked List is Empty");
	}
	else
	{
		start = start->next;
		start->prev = NULL;
		free(temp);
	}
}
void deleteAtLocation()
{
	int loc,i,count=0;
	struct node *del,*temp,*pre;
	temp = start;
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else
	{
		count = countList(start);
		printf("\nEnter Location to delete that value: ");
		scanf("%d",&loc);
		if(loc > count)
			printf("\nYou Cannot Delete that data in that position");
		else
		{
			for(i=1;i<loc-1;i++)
			{
				temp = temp->next;
			}
			del = temp->next;
			temp->next = del->next;
			pre = del->next;
			pre->prev = temp;
			free(del);
		}
	}
}
void searchList()
{
	struct node *temp;
	int count=0,flag=0,value;
	temp = start;
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else
	{
		printf("\nEnter Value to Search: ");
		scanf("%d",&value);
		while(temp != NULL)
		{
			count++;
			if(temp->data == value)
			{
				flag = 1;
				break;
			}
			temp = temp->next;	
		}
		if(flag == 1)
			printf("\n%d Found at Location %d",value,count);
		else
			printf("\n%d Not Found in the List",value);
	}
}
void deleteAtEnd()
{
	struct node *temp,*ptr;
	temp = start;
	if(temp == NULL)
		printf("\nLinked List is Empty");
	else if(temp->next == NULL)
		free(temp);
	else
	{
		while(temp->next != NULL)
		{
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = NULL;
		free(temp);
	}
}
void copyList(struct node *source,struct node *start2)
{
	int count,i;
	struct node *temp,*newNode,*temp2;
	start2 = source;
	temp = start2;
	if(temp == NULL)
		printf("\nList is Empty");
	else
	{
		count = countList(start);
		for(i=1;i<=count;i++)
		{
			newNode = getNode();
			newNode->data = temp->data;
			if(i==1)
			{
				start2 = newNode;
				newNode->next = NULL;
				newNode->prev = NULL;
			}
			else
			{
				temp2 = start2;
				while(temp2->next != NULL)
				{
					temp2 = temp2->next;
				}
				temp2->next = newNode;
				newNode->prev = temp;
				newNode->next = NULL;
			}
			temp = temp->next;
		}
	}
	displayList(start2);
}
void splitList()
{
	int loc,i,count;
	struct node *temp;
	temp = start;
	if(temp == NULL)
		printf("\nList is Empty");
	else
	{
		count = countList(start);
		printf("\nEnter from which location you want to Split the List: ");
		scanf("%d",&loc);
		if(loc > count)
			printf("\nLocation Error");
		else
		{
			for(i=1;i<loc-1;i++)
			{
				temp = temp->next;
			}
			split = temp->next;
			split->prev = NULL;
			temp->next = NULL;
			printf("\nList 1: ");
			displayList(start);
			printf("\nList 2: ");
			displayList(split);
		}
	}
}
void concatList(struct node *s,struct node *d)
{
	struct node *temp;
	temp = s;
	if(temp == NULL || d == NULL)
		printf("\nAnyone Linked List is Empty");
	else
	{
		printf("\nYour Actual List is: ");
		displayList(s);
		printf("\nList 2 is:");
		displayList(d);
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = d;
		d->prev = temp;
		printf("\nAfter Concatenating that List is as: ");
		displayList(s);
	}
}
void deleteAll()
{
	struct node *temp;
	for(temp = start; temp != NULL; temp = temp->next)
	{
		start->next = temp->next;
		free(temp);
		continue;
	}
	start = NULL;
	printf("\nLinked List is now Empty");
}
void main()
{
	int input,ch,count;
	printf("\t\t\t-----Welcome to the Doubly Linked List Execution-----");
	printf("\nCreate a List First\n");
	createList();
	do
	{
		printf("\nWhat Operation you have to Perform with this List: ");
		printf("\n 0.)For creating the New List");
		printf("\n 1.)Insert at Beginnning");
		printf("\n 2.)Insert At End");
		printf("\n 3.)Delete at Beginning");
		printf("\n 4.)Delete at End");
		printf("\n 5.)Count the Number of List");
		printf("\n 6.)Copy the List");
		printf("\n 7.)Search Data from List");
		printf("\n 8.)Display the List");
		printf("\n 9.)Split the List by 2");
		printf("\n10.)Reverse the List");
		printf("\n11.)Insert at Particular Location");
		printf("\n12.)Delete All");
		printf("\n13.)Delete At Particular Location");
		printf("\n14.)Concat that Split List");
		printf("\nEnter your choice from Above: ");
		scanf("%d",&input);
		switch(input)
		{
			case 0:
				createList();
				break;
			case 1:
				insertAtBeginning();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 2:
				insertAtEnd();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 3:
				deleteAtBeginning();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 4:
				deleteAtEnd();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 5:
				count  = countList(start);
				printf("\nTotal Number of Element in List are: %d",count);
				break;
			case 6:
				printf("\nActual List is as follows: ");
				displayList(start);
				printf("\nCopy of List is as follows: ");
				copyList(start,copy);
				break;
			case 7:
				searchList();
				break;
			case 8:
				displayListWithAddress(start);
				break;
			case 9:
				splitList();
				break;
			case 10:
				printf("\nReverse of the List is: ");
				reverseList(start);
				break;
			case 11:
				insertAtLocation();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 12:
				deleteAll();
				break;
			case 13:
				deleteAtLocation();
				printf("\nUpdated List is as follows: ");
				displayList(start);
				break;
			case 14:
				concatList(start,split);
				break;
			default:
				printf("\nInvalid Choice...");
		}
		printf("\nDo You want to Continue (1->Yes & 0->No): ");
		scanf("%d",&ch);
	}while(ch==1);
}
