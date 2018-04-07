#include<stdio.h>

int main()
{       
    int n1, n2, i, min;
    printf("Enter two numbers:\n");
    scanf("%d %d", &n1, &n2);
    min=n1<n2?n1:n2;
    for(i=2;i<=min;i++){
     if(n1%i==0&&n2%i==0)
            break;
    }
    if(i==min+1)
     printf("%d and %d are co-prime:\n",n1, n2);
    else
     printf("%d and %d are not co-prime:\n",n1, n2);
} 
