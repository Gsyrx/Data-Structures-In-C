#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

node *ptr,*temp = NULL, *start = NULL;

void create_node()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data :- ");
    scanf("%d",&(temp->data));
    temp->llink = temp->rlink = NULL;
}
void insert_node()
{
    create_node();
    if(start==NULL)
    {
        start = temp;
    }
    else if(temp->data < start->data)
    {
        temp->rlink = start;
        start->llink = temp;
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->rlink != NULL && temp->data>ptr->data)
        {
            ptr=ptr->rlink;
        }
        if(ptr->rlink == NULL && temp->data> ptr->data)
        {
            ptr->rlink = temp;
            temp->llink = ptr;
        }
        else
        {
            
            temp->rlink = ptr;
            ptr->llink->rlink = temp;
            temp->llink = ptr->llink;
            ptr->llink = temp;
        }
    }
}
void display()
{
    if(start ==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("%d<-->",ptr->data);
            ptr = ptr->rlink;
        }
    }
}
void main()
{
    int n;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Exit");
        printf("\nEnter your choice :- ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insert_node();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}
