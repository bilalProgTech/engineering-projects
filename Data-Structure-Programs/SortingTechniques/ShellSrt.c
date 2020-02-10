/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18g
Write a program to implement Shell Sort
*/
#include <stdio.h>
#define MAX 10

void shellSort(int array[], int n)
{
    int i,j,k,temp,c;
    for(i=n/2;i>0;i=i/2)
    {
        for(j=i;j<n;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(array[k+i] >= array[k])
                    break;
                else
                {
                    temp = array[k];
                    array[k] = array[k+i];
                    array[k+i] = temp;
                }
            }
            printf("\nUpdated Array (after Swapping): ");
            for(c=0;c<n;c++)
            {
            	printf("\t%d",array[c]);
			}
        }
    }
}
int main()
{
    int array[MAX];
    int k,n;
    printf("--------Shell Sort--------");
	printf("\nEnter how many elements you want: ");
    scanf("%d", &n);
	printf("\n");
    for (k=0;k<n;k++)
    {
    	printf("Enter element %d: ",k);
        scanf("%d",&array[k]);
    }
    shellSort(array, n);
    printf("\n\nSorted array is: ");
    for (k=0;k<n;k++)
        printf("\t%d",array[k]);
    printf("\n\n-----Thank You------\n");
    return 0;
}

/*
--------Shell Sort--------
Enter how many elements you want: 8

Enter element 0: 32
Enter element 1: 33
Enter element 2: 45
Enter element 3: 12
Enter element 4: 4
Enter element 5: 89
Enter element 6: 39
Enter element 7: 100

Updated Array (after Swapping):         4       33      45      12      32      89      39      100
Updated Array (after Swapping):         4       33      45      12      32      89      39      100
Updated Array (after Swapping):         4       33      39      12      32      89      45      100
Updated Array (after Swapping):         4       33      39      12      32      89      45      100
Updated Array (after Swapping):         4       33      39      12      32      89      45      100
Updated Array (after Swapping):         4       12      39      33      32      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      89      45      100
Updated Array (after Swapping):         4       12      32      33      39      45      89      100
Updated Array (after Swapping):         4       12      32      33      39      45      89      100

Sorted array is:        4       12      32      33      39      45      89      100

-----Thank You------

*/
