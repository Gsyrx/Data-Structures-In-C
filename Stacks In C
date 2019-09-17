#include<stdio.h>
#define SIZE 5
int top=-1,stack[SIZE];
void push()
{
	int num;
	if(top==SIZE-1)
	{
		printf("OVERFLOW");
	}
	else
	{
		
		printf("Enter the number to be pushed :- ");
		scanf("%d",&num);
		top=top+1;
		stack[top]=num;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("UNDERFLOW");
	}
	else
	{
		printf("The deleted element is %d",stack[top]);
		top=top-1;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
	printf("Stack is empty");
	}
	else
	{
		for(i=top;i>=0;--i)
		{
			printf("%d\n",stack[i]);	
		}
	}
}
void main()
{
	int n;
	while(1)
	{
		printf("\n\n\n1 :- PUSH\n2 :-POP\n3 :-DISPLAY\n4 :- EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Wrong code entered");
		}
	}
}

