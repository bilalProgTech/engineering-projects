/*
Name		: Hungund Bilal
Roll No.	: IT-68
Program Name	:
Write a menu driven program to perform the following operations in an ARRAY
1.) INSERT
2.) DELETE
3.) TRAVERSE
4.) SEARCH
*/
#include<stdio.h>
#define MAX_SIZE 10

void insertArray();
void deleteArray();
void traverseArray();
void searchArray();
void initializeArray();

int array[MAX_SIZE],count=0;

int main()
{
	int input,i,ch;
	printf("-----Welcome to the Array Operation-----\n");
	printf("Initialize your Array First");
	initializeArray();
	printf("\nArray Content: [");
	for(i=0;i<count;i++)
	{
		printf("%d",array[i]);
		printf(",");
	}
	printf("]\n");
	do
	{
		printf("\n1.INSERT\n2.DELETE\n3.TRAVERSE\n4.SEARCH");
		printf("\nEnter what you want to go: ");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				insertArray();
				break;
			case 2:
				deleteArray();
				break;
			case 3:
				traverseArray();
				break;
			case 4:
				searchArray();
				break;
			default:
				printf("\nInvalid Choice...");
		}
		printf("\nDo you want to Continue(1-Yes , 0-No): ");
		scanf("%d",&ch);
	}while(ch!=0);
	printf("------Thank You-------");
	return 0;
}

void initializeArray()
{
	int i;
	printf("\nEnter how many elements you want:");
	scanf("%d",&count);
	printf("\nEnter %d elements:\n",count);
	for(i=0;i<count;i++)
	{
		scanf("%d",&array[i]);
	}
}
void insertArray()
{
	int value,loc,i;
	if(count==MAX_SIZE)
		printf("Array is Full. Insert Not Possible");
	else
	{
		printf("Enter Value/Element to insert: ");
		scanf("%d",&value);
		printf("Enter Location where to insert: ");
		scanf("%d",&loc);
		if(loc>count+1)
			printf("Illegal operation");
		else
		{
			for(i=count;i>=(loc-1);i--)
			{
				array[i+1]=array[i];
			}
			array[loc-1]=value;
			count=count+1;
			traverseArray();
		}
	}
}
void deleteArray()
{
	int loc,i;
	printf("Enter Location to delete Array Element: ");
	scanf("%d",&loc);
	if(loc>count)
		printf("Illegal Operation");
	else
	{
		for(i=(loc-1);i<=(count-2);i++)
		{
			array[i]=array[i+1];
		}
		count=count-1;
		traverseArray();
	}
}
void traverseArray()
{
	int i;
	printf("\nYour Array Elements are: ");
	for(i=0;i<count;i++)
	{
		printf("\n%d",array[i]);	
	}
}
void searchArray()
{
	int loc,i,flag=0;
	printf("Enter Location to Search: ");
	scanf("%d",&loc);
	if(loc>MAX_SIZE)
		printf("Cannot Perform Search Operation");
	else
	{
		for(i=0;i<count;i++)
		{
			if(i==loc)
			{
				flag=1;	
				break;
			}
		}
		if(flag==1)
		{
			printf("\nElement Found and value is: %d",array[loc-1]);
		}
		else
			printf("\nElement Not found");
	}
}
/*
-----Welcome to the Array Operation-----
Initialize your Array First
Enter how many elements you want:5

Enter 5 elements:
1
2
3
4
5

Array Content: [1,2,3,4,5,]

1.INSERT
2.DELETE
3.TRAVERSE
4.SEARCH
Enter what you want to go: 1
Enter Value/Element to insert: 9
Enter Location where to insert: 3

Your Array Elements are:
1
2
9
3
4
5
Do you want to Continue(1-Yes , 0-No): 1

1.INSERT
2.DELETE
3.TRAVERSE
4.SEARCH
Enter what you want to go: 2
Enter Location to delete Array Element: 3

Your Array Elements are:
1
2
3
4
5
Do you want to Continue(1-Yes , 0-No): 1

1.INSERT
2.DELETE
3.TRAVERSE
4.SEARCH
Enter what you want to go: 3

Your Array Elements are:
1
2
3
4
5
Do you want to Continue(1-Yes , 0-No): 1

1.INSERT
2.DELETE
3.TRAVERSE
4.SEARCH
Enter what you want to go: 4
Enter Location to Search: 4

Element Found and value is: 4
Do you want to Continue(1-Yes , 0-No): 0
------Thank You-------
--------------------------------
*/
