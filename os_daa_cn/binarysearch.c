#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int i, j, *array;

int binary_search(int l, int h, int key)
{
    int mid;

    if (l == h)
    {

     if (*(array + l - 1) == key)

        return l;
    else
        return 0;
    }

    mid = (l + h) / 2;

    if (key == *(array + mid - 1))
        return mid;

    else if (key < *(array + mid - 1))
        return binary_search(l, mid - 1, key);
    else
        return binary_search(mid + 1, h, key);
}

void main()
{

    double time_taken;
    int n, key, index;

    printf("\nPlease enter the number of elements :");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);
    printf("Please enter the elements\n");

    for (i = 0; i < n; i++)
    {
        printf("enter the a[%d] element :", i + 1);
        scanf("%d", (array + i));
    }

    printf("\nenter the key/element which you want to search in data :");
    scanf("%d", &key);

    clock_t begin = clock();

    index = binary_search(1, n, key);
    clock_t end = clock();

    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
   

    if (!index)
    {
        printf("\nThe key is not present in the given elements. ");
    }
    else
        printf("the element is present at index number %d",index);
    printf("\nTime taken to execute the search = %f sec\n", time_taken);
}