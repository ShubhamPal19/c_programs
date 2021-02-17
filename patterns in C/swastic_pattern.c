#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j;
    printf("enter the size of pattern : ");
    scanf("%d",&n);
     printf("\n");
      printf("\n");
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(j==1)
            {
                if(i==1||((i>(n-1)/2)&&(i<=n)))
                printf("*");
                else
                printf(" ");

            }
            if((j>1)&&(j<(n+1)/2))
            {
                if((i==1)||(i==((n+1)/2)))
                printf("*");
                else
                {
                    printf(" ");
                }

                
            }
            if(j==(n+1)/2)
            printf("*");
            if(j>(n+1)/2&&j<n)
             {
                 if((i==(n+1)/2)||(i==n))
                 printf("*");
                 else
                 printf(" ");
             }
             if(j==n)
             {
                 if((i<=(n+1)/2)||(i==n))
                   printf("*");
                 else
                 printf(" ");
                 
                 
             }
        }
        printf("\n");
    }
    getch();
    return 0;
}