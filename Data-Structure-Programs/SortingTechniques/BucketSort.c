/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18i
Write a program to implement Bucket Sort
*/
#include <stdio.h>
#define MAX 10

void bucketSort(int array[], int n)
{  
      int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[array[i]])++;

    for (i = 0, j = 0; i < n; i++)  
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}   

int main()
{
    int array[MAX], i, num; 
    printf("--------Bucket Sort--------");
	printf("\nEnter how many elements you want: "); 
    scanf("%d", &num); 
    for (i = 0; i < num; i++)
    {
    	printf("Enter %d element: ",i);
    	scanf("%d", &array[i]); 
	}
	printf("\nSorted Element: "); 
   	bucketSort(array, num); 
    for (i = 0; i < num; i++)
        printf("\t%d", array[i]);   
    printf("\n");  
	printf("\n-----Thank You------\n");   
    return 0;
}
/*
--------Bucket Sort--------
Enter how many elements you want: 5
Enter 0 element: 5
Enter 1 element: 4
Enter 2 element: 3
Enter 3 element: 2
Enter 4 element: 1

Sorted Element:         1       2       3       4       5

-----Thank You------

*/
