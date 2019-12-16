#include<stdio.h>
void toh(int n,char source,char temp,char destination)
{
    if(n==1)
    {
        printf("\nMove disc from %c to %c",source,destination);
    }
    else
    {
        toh(n-1,source,destination,temp);
        printf("\nMove disc from %c to %c",source,destination);
        toh(n-1,temp,source,destination);
    }
    
}
void main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
}
