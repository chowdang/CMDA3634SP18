#include<stdio.h>

int main()
{
    int n1, i;
    printf("Enter a number:\n");
    scanf("%d", &n1);
    for(i=2;i<=n1-1;i++)
        if(n1%i==0)
             break;
    if(i==n1)
        printf("%d is a prime number:\n", n1);
    else
        printf("%d is not a prime number:\n", n1);
}
        
