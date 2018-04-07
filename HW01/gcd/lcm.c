#include<stdio.h>

int main()
{
    int n1, n2, L;
    printf("Enter n1 and n2:\n");
    scanf("%d %d", &n1, &n2);

    for(L=n1>n2?n1:n2;L<=n1*n2;L=L+(n1>n2?n1:n2))
        if(L%n1==0&&L%n2==0)
            break;
    printf("LCM is %d:\n",L);
}
