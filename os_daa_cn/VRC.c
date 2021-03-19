#include <stdio.h>
#include <stdlib.h>

int vrc(int *array, int n, int parity)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(array + i))
        {
            if (temp)
                temp = 0;
            else
                temp = 1;
        }
    }
    if (temp == parity)
        return 1;
    return 0;
}

int main()
{

    int *array, n, parity;

    printf("Please enter the number of bits in data : ");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);

    printf("enter the data\n");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (array + i));
    }

    printf("\nenter the parity bit :");
    scanf("%d", &parity);

    if (vrc(array, n, parity))
        printf("\nthe data is correct\n");
    else
        printf("\nthe data is incorrect\n");

    return 0;
}
