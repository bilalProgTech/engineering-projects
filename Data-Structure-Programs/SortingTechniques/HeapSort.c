/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18f
Write a program to implement Heap Sort
*/
#include<stdio.h>
#include <stdlib.h>
#define MAX 25

void max_heapify(int a[], int i, int heapsize)
{
    int tmp,largest,m;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if((l <= heapsize) && (a[l] > a[i]))
         largest = l;
    else
         largest = i;
    if((r <= heapsize) && (a[r] > a[largest]))
         largest = r ;
    if(largest != i) 
    {
         tmp = a[i];
         a[i] = a[largest];
         a[largest] = tmp;
         max_heapify(a, largest, heapsize);
    }
    
}
void  build_max_heap(int a[], int heapsize)
{
    int i;
    for (i=heapsize/2; i>=0; i--)
    {
         max_heapify(a, i, heapsize);
    }
}
void heap_sort(int a[], int heapsize)
{
    int i,tmp,m;
    build_max_heap(a, heapsize);
    for(i=heapsize;i>0;i--) 
    {
        tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapsize--;
        max_heapify(a, 0, heapsize);
    }
}
int main()
{
    int i, r, heapsize;
   	int array[MAX],n;
	printf("--------Heap Sort--------");
	printf("\nEnter how many elements you want: ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&array[i]);
	}  
    heapsize = n;
    heap_sort(array, heapsize);
    printf("\nAfter Sorting: ");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);
    return 0;
}

/*
--------Heap Sort--------
Enter how many elements you want: 8

Enter element 0: 52
Enter element 1: 14
Enter element 2: 96
Enter element 3: 32
Enter element 4: 28
Enter element 5: 55
Enter element 6: 14
Enter element 7: 20

After Sorting:  14      14      20      28      32      52      55      96
--------------------------------
*/

