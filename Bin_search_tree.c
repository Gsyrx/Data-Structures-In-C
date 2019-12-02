#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;
node *tree,*root,*temp=NULL,*ptr=NULL,*parent;
void create()
{
    temp=(node *)malloc(sizeof(node));
    printf("Enter the data :- ");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ptr->data==temp->data)
            {
                printf("Node exist!!");
                return;
            }
            else if(ptr->data>temp->data)
            {
                ptr=ptr->llink;
            }
            else
                ptr=ptr->rlink;
        }
        if(parent->data<temp->data)
            parent->rlink=temp;
        else
            parent->llink=temp;
    }
}
void inorder( node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d<-->",tree->data);
        inorder(tree->rlink);
    }

}
void postorder( node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d<-->",tree->data);
    }

}
void preorder( node *tree)
{
    if(tree!=NULL)
    {
        printf("%d<-->",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }

}
void display()
{
    printf("The inorder traversal of the tree is :- ");
    inorder(root);
    printf("\nThe postorder traversal of the tree is :- ");
    postorder(root);
    printf("\nThe preorder traversal of the tree is :- ");
    preorder(root);

}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : exit(0);
        }

    }

}
