#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int Q[MAX],front=-1,rear=-1,data,ditem;
void check(int data)
{
    int i,j;
    for( i =0;i<=rear;i++)
    {
        if(data>=Q[i])
        {
            for(j=rear+1;j>i;j--)
            {
                Q[j]=Q[j-1];

            }
            Q[i]=data;
            return;
        }
    }
    Q[i]=data;
}
void insert()
{
    if(rear==(MAX-1))
    {
        printf("Queue is full !!");
        return;
    }
    else
    {
        printf("Enter the data :- ");
        scanf("%d",&data);
        if(rear==-1&&front==-1)
        {
            rear=0;
            front=0;
            Q[rear]=data;
            return;
        }
        else
            check(data);

        rear++;
    }
}
        
void delete()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty !!");
    else
    {
        ditem=Q[front];
        printf("The deleted item is %d",ditem);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1 ;
        }
    }
}

void display()
{
    if(rear == -1 && front == -1)
        printf("The list is empty !!");
    else
    {
        for(int i =front ; i<=rear ; i++)
        {
            printf("%d<-->", Q[i]);
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
