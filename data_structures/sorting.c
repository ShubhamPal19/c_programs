#include <stdio.h>

void sorting(int *a, int n);
void main()
{
    int n, *a, i;
    printf("enter the size of array :");
    scanf("%d", &n);
    a = (int *)malloc(i * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("enter the value of a[%d]\n", i);
        scanf("%d", &(*(a + i)));
    }
    sorting(a,n);
   
    for (i = 0; i < n; i++)
    {
        printf("the value of a[%d] is :%d\n", i, *(a + i));
    }
}
void sorting(int *a, int n)
{ int tem;
    int j;
    for (int k = 0; k < n; k++)
    {
        
        for (j = 0; j < n-1; j++)
        {
          
            if ((*(a + j)) < *(a + j + 1))
            {
               
                tem = *(a + j);
                *(a + j) = *(a + j + 1);
                
                *(a + j + 1) = tem;
                
            }
        }
    }
    return;
    
}
