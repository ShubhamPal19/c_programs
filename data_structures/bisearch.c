#include <stdio.h>
#include <stdlib.h>
int search(int a, int *p, int n);

int main()
{
    int a, *ar, n;
    printf("enter the no of element");
    scanf("%d", &n);

    ar = (int *)malloc(n * sizeof(int));
    printf("enter the values in sorted form");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(*(ar + i)));
    }
    // for (int j = 0; j < n; j++)
    // {
    //     printf("%d\n", (*(ar + j)));
    // }
    printf("enter the searching element");
    scanf("%d", &a);
    if (search(a, ar, n))
        printf("yes");
    else
        printf("no");

    return 0;
}
int search(int a, int *p, int n)
{   
    int c = 0;
    if (n % 2 == 0)
        n = n / 2;
    else
    {
        c = 1;
        n = (n + 1) / 2;
    }
    if (*(p + n - 1) == a)
        return 1;
    else if(n==1)
    {
        return 0;
    }
       
    else if (*(p + n - 1) > a)
    {
        if (c)
        {
            return search(a, p, n);
        }
        else
        {
            return search(a, p, n - 1);
        }
    }
    else if(*(p + n - 1) < a)
    {
        return search(a, (p + n), n);
    }

    
}
