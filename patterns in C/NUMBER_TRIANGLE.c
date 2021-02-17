#include <stdio.h>
#include<conio.h>
int main()
{
    int  b, r, j, a= 1;
    printf("enter the no. of rows");
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
    {
        for (j=a; j <a+i;j++)
        {
            printf("%d   ", j);
            
        }
         a=j;
        printf("\n");
    }
    getch();
    return 0;
    
}