#include <stdio.h>
#include <stdlib.h>

int arr[20], a[10], b[10];

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    for (i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

        i=0;
        j=0;
        k=l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r)
    {
        
        int m;
        m = (l + r)  / 2;
        mergeSort(l,m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }

    
}

void printArray(int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, i;

    printf("enter the number of elements in array(max 20) : ");
    scanf("%d", &n);

    printf("enter the  elements of array  \n");

    for (i = 0; i < n; i++)
    {
        printf("enter the element a[%d] :", i);
        scanf("%d", &(arr[i]));
    }
    printf("Given array is \n");
    printArray(n);

    mergeSort(0, n - 1);

    printf("\nSorted array is \n");
    printArray(n);
    return 0;
}