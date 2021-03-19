#include <stdio.h>
#include <stdlib.h>

int *array, *divisor, *temp, i;

void append_crc(int n, int m)
{

    int p, flag, j;

    temp = (int *)calloc(m, sizeof(int));
    p = 0;

    for (i = 0; i < m + n - 1;)
    {
        flag = 1;
        if (*(temp + p % m) == 0)
        {
            *(temp + p % m) = *(array + i);
            p++;
            i++;
            flag = 0;
        }

        if (flag || (i == m + n - 1 && *(temp + p % m) == 1))
            for (j = 0; j < m; j++)
            {
                if (*(divisor + j) == *(temp + (p + j) % m))
                    *(temp + (p + j) % m) = 0;
                else
                    *(temp + (p + j) % m) = 1;
            }
    }
    //   append crc with data
    for (j = 1; j < m; j++)
    {
        *(array + n + j - 1) = *(temp + (p + j) % m);
    }
}

void main()
{
    int n, m;

    printf("\nPlease enter the number of bits in data : ");
    scanf("%d", &n);
    printf("Please enter the number of bits in divisor: ");
    scanf("%d", &m);

    array = (int *)malloc(sizeof(int) * (m + n - 1));
    divisor = (int *)malloc(sizeof(int) * (m));
    printf("Please enter the data bits\n");

    for (i = 0; i < n + m - 1; i++)
    {
        if (i < n)
        {
            scanf("%d", array + i);
            continue;
        }
        *(array + i) = 0;
    }

    printf("Please enter the divisor bits\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d", divisor + i);
    }

    append_crc(n, m);

    printf("\nThe final data to be transmitted  is \n");
    for (i = 0; i < n + m - 1; i++)
    {
        printf("%d ", *(array + i));
    }
    
}
