#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;
node *last = NULL, *temp=NULL,*ptr=NULL,*cur;

void insert()
{
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the data :- ");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}


void delete()
{

    if(last == NULL)
        printf("\nThe list is empty !!");

    ptr = last->link;

    if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {
        last->link = ptr->link;
        ptr->link = NULL;
        free(ptr);
    }
}


void display()
{

    if(last == NULL)
        printf("\nThe list is empty !!");
    else
    {
        temp = last->link;
        while(temp != last)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("%d-->", temp->data);
        printf("\n");
    }
}


void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice :- ");
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
