/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18c
Write a program to implement Insertion Sort
*/
#include<stdio.h>
#define MAX 10

void insertionSort(int *array,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp = array[i];
		j = i - 1;
		while(temp<=array[j] && j>=0)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}

int main()
{
	int i,array[MAX],n,c;
	printf("--------Insertion Sort--------");
	printf("\nEnter how many elements you want: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&array[i]);
	}
	insertionSort(array,n);
	printf("\nSorted Array: ");
	for (c = 0; c <= n - 1; c++) 
	{
		printf("\t%d", array[c]);
 	}
	printf("\n\n-----Thank You------\n");
}

/*
--------Insertion Sort--------
Enter how many elements you want: 5

Enter element 1: 5
Enter element 2: 4
Enter element 3: 3
Enter element 4: 2
Enter element 5: 1

Sorted Array:   1       2       3       4       5

-----Thank You------

--------Insertion Sort--------
Enter how many elements you want: 5

Enter element 1: 12
Enter element 2: 58
Enter element 3: 63
Enter element 4: 48
Enter element 5: 77

Sorted Array:   12      48      58      63		77

-----Thank You------
*/
