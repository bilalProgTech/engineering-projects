/*
Name 			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 2a
Define a structure data type called time_struct containing 3 memebers int hour, int minute and int second.
Write functions that accept the structure to perform the following operations:
1. Input new time
2. Display the time
3. Update the time such that the function accepts the time_struct and increments the time by one second.
(If the increment results in 60 seconds, the then second member is set to 0 
and the minute is incremented by 1. Then, if the result is 60 minutes, the 
minute memeber is set to 0 and the hour member is incremented by 1. Finally 
when the hour becomes 24, it is set to zero.)
*/
#include<stdio.h>

struct time_struct
{
	int hour,min,sec;
};

struct time_struct insertTimer(int,int,int);
struct time_struct updateTimer(struct time_struct);
void displayTimer(struct time_struct);

int main()
{
	int input,ch,h,m,s;
	struct time_struct result;
	printf("------Welcome to Timer Program------");
	do
	{
		printf("\n1.) Insert new Time");
		printf("\n2.) Update Time by 1 Minute");
		printf("\n3.) Display Time");
		printf("\nEnter you choice: ");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("\nEnter Hour:Minute:Second: ");
				scanf("%d %d %d",&h,&m,&s);
				if(h>=24 || m>=60 || s>=60)
					printf("Invalid Time");
				else
				{
					result = insertTimer(h,m,s);
					displayTimer(result);
				}
				break;
			case 2:
				result = updateTimer(result);
				displayTimer(result);
				break;
			case 3:
				displayTimer(result);
				break;
			default:
				printf("\nInvalid Choice...");
		}
		printf("\nDo You want to Continue (1->Yes & 0->No): ");
		scanf("%d",&ch);
	}while(ch == 1);
	printf("Thank You");
	return 0;
}
struct time_struct insertTimer(int h,int m,int s)
{
	struct time_struct t;
	t.hour =  h;
	t.min = m;
	t.sec = s;
	return t;
}
struct time_struct updateTimer(struct time_struct t)
{
	if(t.sec == 59)
	{
		t.sec=00;
		if(t.min == 59)
		{
			t.min=00;
			if(t.hour == 23)
				t.hour=00;
			else
				t.hour++;
		}
		else
			t.min++;
	}
	else
		t.sec++;
	return t;
}
void displayTimer(struct time_struct t)
{
	printf("\nTime is-> %d : %d : %d",t.hour,t.min,t.sec);
}
/*
------Welcome to Timer Program------
1.) Insert new Time
2.) Update Time by 1 Minute
3.) Display Time
Enter you choice: 1

Enter Hour:Minute:Second: 23
59
59

Time is-> 23 : 59 : 59
Do You want to Continue (1->Yes & 0->No): 1

1.) Insert new Time
2.) Update Time by 1 Minute
3.) Display Time
Enter you choice: 2

Time is-> 0 : 0 : 0
Do You want to Continue (1->Yes & 0->No): 1

1.) Insert new Time
2.) Update Time by 1 Minute
3.) Display Time
Enter you choice: 1

Enter Hour:Minute:Second: 24
32
96
Invalid Time
Do You want to Continue (1->Yes & 0->No): 1

1.) Insert new Time
2.) Update Time by 1 Minute
3.) Display Time
Enter you choice: 1

Enter Hour:Minute:Second: 12
54
59

Time is-> 12 : 54 : 59
Do You want to Continue (1->Yes & 0->No): 1

1.) Insert new Time
2.) Update Time by 1 Minute
3.) Display Time
Enter you choice: 2

Time is-> 12 : 55 : 0
Do You want to Continue (1->Yes & 0->No): 0
Thank You
--------------------------------
*/
