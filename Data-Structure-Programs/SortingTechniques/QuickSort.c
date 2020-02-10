/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18d
Write a program to implement Quick Sort
*/
#include<stdio.h>
#define MAX 5
void quickSort(int x[MAX],int first,int last)
{
	int pivot,j,temp,i;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(x[i]<=x[pivot]&&i<last)
				i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		printf("\nUpdated Array After Swapping: ");
		for(i=0;i<last+1;i++)
			printf("\t%d",x[i]);
		quickSort(x,first,j-1);
		quickSort(x,j+1,last);
	 }
}

int main(){
	int x[MAX],size,i;
	printf("--------Quick Sort--------");
	printf("\nEnter how many elements you want: ");
	scanf("%d",&size);

	for(i=0;i<size;i++)
	{
		printf("Enter %d Element: ",i);
		scanf("%d",&x[i]);
	}
	
	quickSort(x,0,size-1);	

	printf("\nSorted elements: ");
	for(i=0;i<size;i++)
		printf("\t%d",x[i]);
	printf("\n\n-----Thank You------\n");	
	return 0;
}

/*
--------Quick Sort--------
Enter how many elements you want: 5
Enter 0 Element: 1
Enter 1 Element: 2
Enter 2 Element: 3
Enter 3 Element: 5
Enter 4 Element: 4

Updated Array After Swapping:   1       2       3       5       4
Updated Array After Swapping:   1       2       3       5       4
Updated Array After Swapping:   1       2       3       5       4
Updated Array After Swapping:   1       2       3       4       5
Sorted elements:        1       2       3       4       5

-----Thank You------

--------Quick Sort--------
Enter how many elements you want: 5
Enter 0 Element: 48
Enter 1 Element: 69
Enter 2 Element: 31
Enter 3 Element: 12
Enter 4 Element: 58

Updated Array After Swapping:   31      12      48      69      58
Updated Array After Swapping:   12      31
Updated Array After Swapping:   12      31      48      58      69
Sorted elements:        12      31      48      58      69

-----Thank You------
*/

