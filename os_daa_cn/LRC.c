#include <stdio.h>
#include <stdlib.h>
int i, j, n, m;

void lrc(int *array, int *parity)
{
    int temp,error=0;
    printf("error in bit(starting from lsb)  :  ");
    for (i = n-1; i >=0; i--)
    {
        temp=0;
        for (j = 0; j < m; j++)
        {
            if (*(array + j * n + i))
            {
                if (temp)
                    temp = 0;
                else
                    temp = 1;
            }

        }
        if(temp!=*(parity+i))
            {
                error=1;
                printf("%d ",(n-i));
            }
    }
    printf("\n");
    if(!error)
    {
        printf("there is no error in data\n");
    }
}
void main()
{
    int *array, *parity;
    printf("%d",6%5); 

    printf("\nPlease enter the number of packets/block in data : ");
    scanf("%d", &m);
    printf("Please enter the number of bits in each packet/block : ");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n * m);
    parity = (int *)malloc(sizeof(int) * n);
    printf("Enter  the data\n");

    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", (array + j * n + i));
        }
    }


    printf("Enter  the parity block\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (parity + i));
    }
    lrc(array,parity);
}