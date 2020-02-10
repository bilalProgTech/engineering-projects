/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18a
Write a program to implement Bubble Sort
*/
#include<stdio.h>
#define MAX 10

void bubbleSort(int array[],int n)
{
	int i,j,k,temp,flag=0;
	for(i=n;i>1;i--)
	{
		for(j=0;j<n-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 1)
		{
			printf("\nAfter Pass %d",i);
			for(k=0;k<n;k++)
			{
				printf("\t%d",array[k]);
			}
		}
	}
	if(i == 0)
		printf("\nThe Array is in Sorted Order");
	else
		printf("\n\nTotal Number of passes are %d",i);
}

int main()
{
	int i,array[MAX],n;
	printf("--------Bubble Sort--------");
	printf("\nEnter how many elements you want: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&array[i]);
	}
	bubbleSort(array,n);
	printf("\n\n-----Thank You------\n");
}
/*
--------Bubble Sort--------
Enter how many elements you want:
5

Enter element 1: 52
Enter element 2: 36
Enter element 3: 74
Enter element 4: 12
Enter element 5: 100

After Pass 0    36      52      12      74      100
After Pass 1    36      12      52      74      100
After Pass 2    12      36      52      74      100
After Pass 3    12      36      52      74      100
After Pass 4    12      36      52      74      100

Total Number of passes are 5

-----Thank You------

--------------------------------

--------Bubble Sort--------
Enter how many elements you want: 5

Enter element 1: 12
Enter element 2: 36
Enter element 3: 98
Enter element 4: 102
Enter element 5: 550

The Array is in Sorted Order

-----Thank You------

--------------------------------

--------Bubble Sort--------
Enter how many elements you want: 5

Enter element 1: 5
Enter element 2: 4
Enter element 3: 3
Enter element 4: 2
Enter element 5: 1

After Pass 0    1       4       3       2       5
After Pass 1    1       3       2       4       5
After Pass 2    1       2       3       4       5
After Pass 3    1       2       3       4       5
After Pass 4    1       2       3       4       5

Total Number of passes are 5

-----Thank You------

--------------------------------
*/
