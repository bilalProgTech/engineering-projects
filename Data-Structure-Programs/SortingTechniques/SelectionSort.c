/*
Name			: Hungund Bilal 
Roll No.		: IT-68
Program Name	: ID - 18b
Write a program to implement Selection Sort
*/
#include<stdio.h>
#define MAX 5
void selectionSort(int array[],int n)
{
	int i,j,min,temp,k,passes;
	for(i=0,passes=1;i<n;i++,passes++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(array[j]<array[min])
			{
				min = j;
			}
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
		printf("\nAfter Pass %d",passes);
		for(k=0;k<n;k++)
		{
			printf("\t%d",array[k]);
		}
	}
	printf("\n\nTotal Number of passes are %d",passes-1);
}

int main()
{
	int i,array[MAX],n;
	printf("--------Selection Sort--------");
	printf("\nEnter how many elements you want: ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&array[i]);
	}
	selectionSort(array,n);
	printf("\n\n-----Thank You------\n");
}
/*
--------Selection Sort--------
Enter how many elements you want: 5

Enter element 0: 5
Enter element 1: 4
Enter element 2: 3
Enter element 3: 2
Enter element 4: 1

After Pass 1    1       5       4       3       2
After Pass 2    1       2       5       4       3
After Pass 3    1       2       3       5       4
After Pass 4    1       2       3       4       5
After Pass 5    1       2       3       4       5

Total Number of passes are 5

-----Thank You------

--------Selection Sort--------
Enter how many elements you want: 5

Enter element 0: 1
Enter element 1: 2
Enter element 2: 3
Enter element 3: 5
Enter element 4: 4

After Pass 1    1       2       3       5       4
After Pass 2    1       2       3       5       4
After Pass 3    1       2       3       5       4
After Pass 4    1       2       3       4       5
After Pass 5    1       2       3       4       5

Total Number of passes are 5

-----Thank You------

--------------------------------

--------Selection Sort--------
Enter how many elements you want: 5

Enter element 0: 28
Enter element 1: 96
Enter element 2: 36
Enter element 3: 102
Enter element 4: 87

After Pass 1    28      96      36      102     87
After Pass 2    28      36      96      102     87
After Pass 3    28      36      87      102     96
After Pass 4    28      36      87      96      102
After Pass 5    28      36      87      96      102

Total Number of passes are 5

-----Thank You------

--------------------------------
*/
