/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 18h
Write a program to implement Radix Sort
*/
#include<stdio.h>
#define MAX 10

int largestNumber(int array[], int n)
{
    int large = array[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < array[i])
            large = array[i];
    }
    return large;
}

void radixSort(int array[], int n)
{
	int bucket[MAX][MAX], b_count[MAX];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    large = largestNumber(array, n);
    printf("The Largest Element in an Array: %d\n\n",large);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }

    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < MAX; i++)
        {
            b_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (array[i] / divisor) % 10;
            bucket[remainder][b_count[remainder]] = array[i];
            b_count[remainder] += 1;
        }
        
        i = 0;
        for(k = 0; k < MAX; k++)
        {
            for(j = 0; j < b_count[k]; j++)
            {
            	array[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
		printf("Updated Array: ");
        for(i = 0; i < n; i++)
            printf("%d\t",array[i]);
        printf("\n");
    }
}

int main()
{
    int i, n, array[MAX];
    printf("--------Radix Sort--------");
	printf("\nEnter how many elements you want: ");
    scanf("%d",&n);
	printf("\n");
    for(i = 0; i < n; i++)
    {
    	printf("Enter element %d: ",i);
        scanf("%d",&array[i]);
    }
    radixSort(array,n);
    printf("\nSorted Array is:");
    for(i = 0; i < n; i++)
        printf("\t%d",array[i]);
    printf("\n");
    printf("\n-----Thank You------\n");
    return 0;
}

/*
--------Radix Sort--------
Enter how many elements you want: 10

Enter element 0: 8575
Enter element 1: 6932
Enter element 2: 1586
Enter element 3: 2203
Enter element 4: 7411
Enter element 5: 1000
Enter element 6: 8963
Enter element 7: 1009
Enter element 8: 3354
Enter element 9: 874556
The Largest Element in an Array: 874556

Updated Array: 1000     7411    6932    2203    8963    3354    8575    1586    874556  1009
Updated Array: 1000     2203    1009    7411    6932    3354    874556  8963    8575    1586
Updated Array: 1000     1009    2203    3354    7411    874556  8575    1586    6932    8963
Updated Array: 1000     1009    1586    2203    3354    874556  6932    7411    8575    8963
Updated Array: 1000     1009    1586    2203    3354    6932    7411    8575    8963    874556
Updated Array: 1000     1009    1586    2203    3354    6932    7411    8575    8963    874556

Sorted Array is:        1000    1009    1586    2203    3354    6932    7411    8575    8963    874556

-----Thank You------

--------------------------------

*/
