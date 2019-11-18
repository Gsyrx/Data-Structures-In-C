#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int rear=-1,front=-1,CQ[SIZE],item,ditem,i;

void insert()
{
    if(rear == (front - 1) || (front == 0 && rear == (SIZE-1)))
        printf("The circular queue is full !!");
    else
    {
        printf("Enter the number to be pushed :- ");
        scanf("%d", &item);

        if(front == -1 && rear == -1)
            front = 0;

        rear = (rear + 1) % SIZE ;
        CQ[rear] = item;
    }
}

void delete()
{
    if(rear == -1 && front == -1)
    {
        printf("The circular queue is empty !!");
    }
    else
    {
        ditem=CQ[front];
        printf("The deleted item is %d",ditem);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE ;
    }
}

void display()
{
    if(rear == -1 && front == -1)
        printf("The circular queue is empty !!");
    else
    {
        for( i = front ; i != rear ; i = (i+1)%SIZE)
        {
            printf("%d\n", CQ[i]);
        }
        printf("%d\n", CQ[i]);
        
        for(i=0;i<=3;i++)
        {
            printf("%d - %d\n",i,CQ[i]);
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}
