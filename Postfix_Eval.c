#include<stdio.h>
#include<stdlib.h>

char postfix[30], ch;
int num, top = -1, op1, op2, res, s[30];

void PUSH(int num)
{
    s[++top] = num;
}
int POP()
{
    int ditem;
    ditem=s[top];
    top--;
    return (ditem);
}
void main()
{
    int j =0;
    printf("Enter the postfix expression :- ");
    gets(postfix);

    while(postfix[j] != '\0')
    {
        ch = postfix[j];
        if(isalpha(ch))
        {
            printf("Enter the value for %c  :- ",ch);
            scanf("%d", &num);
            PUSH(num);
        }
        else
        {
            op2 = POP();
            op1 = POP();
            switch(ch)
            {
                case '+' : PUSH(op1+op2);
                            break;
                case '*' : PUSH(op1*op2);
                            break;
                case '/' : PUSH(op1/op2);
                            break;
                case '-' : PUSH(op1-op2);
                            break;
                default:  printf("Wrong operator !!");
            }
        }
        j++;
    }
    if(top==0)
    printf("Output = %d", s[top]);
    else
    printf("Invalid postfix expression !!!");
}
