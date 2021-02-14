#include <stdio.h>
int reversenum(int x, int reverse)
{
    if (x == 0)
        return reverse;
    int y = x % 10;
    return (reversenum(x / 10, reverse * 10 + y));
}
void main()
{
    int x, a;
    printf("enter the number you ");
    scanf("%d", &x);
    x = reversenum(x, 0);
    printf("the reverse of the given number is :%d", x);
    return;
}