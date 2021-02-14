#include <stdio.h>
#include<conio.h>
int main()
{
    int n, j,i;
    int m[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("enter the no. of rows ");
    scanf("%d", &n);
    for (j = 0; j < n; j++)
    {
        for (int i = n; i > j; i--)
        {
            printf(" \t");
        }
       
        
        {
            for (i = 10 - j; i < 11 + j;i=i+2 )
            { 
                m[i]=m[i+1]+m[i-1];
            printf("%d\t\t",m[i]);
            
            }
            printf("\n");
        }
    }
    getch();
}
