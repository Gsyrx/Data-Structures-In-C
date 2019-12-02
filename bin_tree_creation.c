#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
int islchild(struct node *tree)
{
    int ch;
    printf("Do you want a left child for %d ?   1.Yes   2.No\n",tree->data);
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else
        return 0;
}
int isrchild(struct node *tree)
{
    int ch;
    printf("Do you want a right child for %d ?   1.Yes  2.No\n",tree->data);
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else 
    return 0;
}
void create(struct node *tree)
{
    if (islchild(tree)==1)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data :- ");
        scanf("%d", &temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        tree->llink=temp;
        create(temp);
    }
    else
        tree->llink=NULL;

    if (isrchild(tree)==1)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data :- ");
        scanf("%d", &temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        tree->rlink=temp;
        create(temp);
    }
    else
        tree->rlink=NULL;
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d",tree->data);
        inorder(tree->rlink);
    }

}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d",tree->data);
    }

}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }

}
void main()
{
    struct node *root;
    root=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :- ");
    scanf("%d", &root->data);
    root->llink=NULL;
    root->rlink=NULL;
    create(root);
    printf("The inorder traversal of the tree is :- ");
    inorder(root);
    printf("\nThe postorder traversal of the tree is :- ");
    postorder(root);
    printf("\nThe preorder traversal of the tree is :- ");
    preorder(root);
}
