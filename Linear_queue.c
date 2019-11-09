#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int rear = -1, front = -1, Q[SIZE], item, ditem;

void insert()
{
    if(rear == (SIZE-1))
        printf("Queue is full !!\n");
    else
    {
        printf("\nEnter the element to be pushed :-  ");
        scanf("%d", &item);
        if(rear == -1 && front == -1)
        {
            rear = 0 ;
            front = 0 ;
        }
        else
        {
            rear = rear +1 ;
        }
        Q[rear] = item;
    }

}

void delete()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty !!\n");
    else
    {
        ditem = Q[front];
        printf("The deleted element is :- %d", ditem);
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
        printf("Queue is empty !!\n");
    else
    {
        for(int i =front ; i<=rear ; i++)
        {
            printf("%d\n", Q[i]);
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the choice :-  ");
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
