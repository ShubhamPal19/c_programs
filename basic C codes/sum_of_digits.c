#include <stdio.h>

void main()
{
    int n, i, sum;
    sum = 0;

    printf("\nEnter the value of integer: ");
    scanf("%d", &n);
    while (n > 0)
    {

        sum = sum + n % 10;

        n = n / 10;
    }

    printf("\nthe sum of digits is : %d", sum);
}