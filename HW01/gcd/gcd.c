#include<stdio.h>
int gcd(int x, int y);

int main()
{
    int n1, n2, g;
    printf("Enter n1 and n2:\n");
    scanf("%d %d", &n1,&n2);

    g = gcd(n1, n2);

    if (g < 0){
         g *= -1;
    }
    printf("GCD(%d, %d) = %d\n", n1 , n2, g);
    return 0;

}
int gcd (int x, int y){
    if (y == 0) return x;
    else return gcd(y, x%y);
}
