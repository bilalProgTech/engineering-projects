/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18e
Write a program to implement Merge Sort
*/
#include<stdio.h>
void merge(int [],int ,int ,int );
void part(int [],int ,int );
int main()
{
	int arr[30];
	int i,size;
	printf("-------Merge Sort-------");
	printf("\nEnter how many element you want: ");
	scanf("%d",&size);
	for(i=0; i<size; i++)
	{
		printf("Enter %d element : ",i+1);
		scanf("%d",&arr[i]);
	}
	part(arr,0,size-1);
	printf("\nSorted Element: ");
	for(i=0; i<size; i++)
		printf("\t%d",arr[i]);
	return 0;
}

void part(int arr[],int min,int max)
{
	int mid;
	if(min<max)
	{
		mid=(min+max)/2;
		part(arr,min,mid);
		part(arr,mid+1,max);
		merge(arr,min,mid,max);
	}
}

void merge(int arr[],int min,int mid,int max)
{
	int tmp[30];
	int i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++)
	{
		if(arr[j]<=arr[m])
		{
			tmp[i]=arr[j];
			j++;
		}
		else
		{
			tmp[i]=arr[m];
 			m++;
		}
	}
	if(j>mid)
	{
		for(k=m; k<=max; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=mid; k++)
		{
			tmp[i]=arr[k];
	 		i++;
		}
	}
	for(k=min; k<=max; k++)
		arr[k]=tmp[k];
}
/*
-------Merge Sort-------
Enter how many element you want: 5
Enter 1 element : 96
Enter 2 element : 32
Enter 3 element : 85
Enter 4 element : 74
Enter 5 element : 10

Sorted Element:         10      32      74      85      96

-------Merge Sort-------
Enter how many element you want: 5
Enter 1 element : 1
Enter 2 element : 2
Enter 3 element : 3
Enter 4 element : 5
Enter 5 element : 4

Sorted Element:         1       2       3       4       5
--------------------------------
*/
