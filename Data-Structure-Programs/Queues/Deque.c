/*
Name 			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - 11
Write a menu driven program to implement input and output restricted DEQUE.  
Assumption:  
In input restricted deque insertion always happens in the left.  
In output restricted deque deletion always happens in the right
*/
#include<stdio.h>
#include<conio.h>
int deque[10];
int l=-1,r=-1;
main()
{
	int ch;
	int g=0;
	do
	{
		printf("\nMenu is:\n");
		printf("\n1.\tInput restricted.\n");
		printf("\n2.\tOutput restricted.\n");
		printf("\nEnter your option:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:inputdeque();
					break;
			case 2:outputdeque();
					break;
			default:printf("\nINVALID INPUT\n");
		}
		printf("\nDo you wish to conitnue on the main menu?(1-yes \ 0-No)\n");
		scanf("%d",&g);
	}while(g!=0 && g<2);
}
void inputdeque()
{
	int a=0,b=0;
	do
	{
		printf("\nINPUT RESTRICTED:\n");
		printf("\n1.Insert at left.\n");
		printf("\n2.Delete at left.\n");
		printf("\n3.Delete at right.\n");
		printf("\n4.Display\n");
		printf("\nEnter your option:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:insertleft();
					break;
			case 2:deleteleft();
					break;
			case 3:deleteright();
					break;
			case 4:display();
			default:printf("\nINVALID INPUT\n");
		}
		printf("\nDo you want to continue?(1-yes\ 0-no)\n");
		scanf("%d",&b);		
	}while(b!=0 && b<2);
}
void outputdeque()
{
	int x=0,y=0;
	do
	{
		printf("\nOUTPUT RESTRICTED:\n");
		printf("\n1.Insert at left.\n");
		printf("\n2.Insert at right.\n");
		printf("\n3.Delete at right.\n");
		printf("\n4.Display\n");
		printf("\nEnter your option:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:insertleft();
					break;
			case 2:insertright();
					break;
			case 3:deleteright();
					break;
			case 4:display();
			default:printf("\nINVALID INPUT\n");
		}
		printf("\nDo you want to continue?(1-yes\ 0-no)\n");
		scanf("%d",&y);		
	}while(y!=0 && y<2);
}
void insertleft()
{
	int d;
	printf("\nEnter the value:\n");
	scanf("%d",&d);
	if((l==0&&r==9)||(r==l-1))
	{
		printf("\nOVERFLOW CONDITION\n");
	}
	if(l==-1)
		l=r=0;
	else
	{
		if(l==0)
			l=9;
		else
			l=l-1;
	}
	deque[l]=d;
	display();
}
void insertright()
{
	int d;
	printf("\nEnter the value:\n");
	scanf("%d",&d);
	if((l==0&&r==9)||(r==l-1))
	{
		printf("\nOVERFLOW CONDITION\n");
	}
	if(l==-1)
		l=r=0;
	else
	{
		if(r==9)
			r=0;
		else
			r=r+1;
	}
	deque[r]=d;
	display();
}
void deleteleft()
{
	if(l==-1)
		printf("\nOVERFLOW CONDITION\n");
	printf("\nThe deleted element is:\t%d\n",deque[l]);
	if(l==r)
		l=r=-1;
	else
	{
		if(l==9)
			l=0;
		else
			l=l+1;
	}
	display();
}
void deleteright()
{
	if(l==-1)
		printf("\nOVERFLOW CONDITION\n");
	printf("\nThe deleted element is:\t%d\n",deque[r]);
	if(l==r)
		l=r=-1;
	else
	{
		if(r==9)
			r=9;
		else
			r=r-1;
	}
	display();
}
void display()
{
	int front=l,rear=r;
	if(front==-1)
	{
		printf("\nQUEQUE IS EMPTY.\n");
	}
	printf("\nElements of the queque are:\n");
	if(front<=rear)
	{
		while(front<=rear)
		{
			printf("\t%d",deque[front]);
			front++;
		}
	}
	else
	{
		while(front<=9)
		{
			printf("\t%d",deque[front]);
			front++;
		}
		front=0;
		while(front<=rear)
		{
			printf("\t%d",deque[front]);
			front++;
		}
	}
	printf("\n");
}
/*

Menu is:

1.      Input restricted.

2.      Output restricted.

Enter your option:
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
1

Enter the value:
25

Elements of the queque are:
        25

Do you want to continue?(1-yes 0-no)
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
1

Enter the value:
32

Elements of the queque are:
        32      25

Do you want to continue?(1-yes 0-no)
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
2

The deleted element is: 32

Elements of the queque are:
        25

Do you want to continue?(1-yes 0-no)
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
4

Elements of the queque are:
        25

INVALID INPUT

Do you want to continue?(1-yes 0-no)
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
3

The deleted element is: 25

QUEQUE IS EMPTY.

Elements of the queque are:
        0

Do you want to continue?(1-yes 0-no)
1

INPUT RESTRICTED:

1.Insert at left.

2.Delete at left.

3.Delete at right.

4.Display

Enter your option:
4

QUEQUE IS EMPTY.

Elements of the queque are:
        0

INVALID INPUT

Do you want to continue?(1-yes 0-no)
0
Do you wish to conitnue on the main menu?(1-yes  0-No)
1
Menu is:

1.      Input restricted.

2.      Output restricted.
Enter your option:
2
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
1
Enter the value:
52
Elements of the queque are:
        52
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
1
Enter the value:
36
Elements of the queque are:
        36      52
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
1
Enter the value:
28
Elements of the queque are:
        28      36      52
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
1
Enter the value:
36
Elements of the queque are:
        36      28      36      52
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
2
Enter the value:
36
Elements of the queque are:
        36      28      36      52      36
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
3
The deleted element is: 36
Elements of the queque are:
        36      28      36      52
Do you want to continue?(1-yes 0-no)
1
OUTPUT RESTRICTED:

1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display
Enter your option:
1
Enter the value:
2
Elements of the queque are:
        2       36      28      36      52

Do you want to continue?(1-yes 0-no)
1

OUTPUT RESTRICTED:
1.Insert at left.

2.Insert at right.

3.Delete at right.

4.Display

Enter your option:
4
Elements of the queque are:
        2       36      28      36      52

INVALID INPUT
Do you want to continue?(1-yes 0-no)
0
Do you wish to conitnue on the main menu?(1-yes  0-No)
0
--------------------------------*/

