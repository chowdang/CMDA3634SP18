#include<stdio.h>

int isGenerator (int i, int range)
{
    int j = 0;
    int inc = 2;
    while (inc <= range) {
	if (j % range >= range)
	    return 0;
	j *= j;
	inc++;
    }
    return 1;
}

int main() 
{
    int n;
    printf("Enter a prime number: ");
    scanf("%d", &n);        
    int i = 2;
    for(; i< n; i++) {
	if (isGenerator(i, n) == 1) {
	    printf("%d is a generator of Z_%d.\n", i, n);
	}
    }

    return 0;
}
