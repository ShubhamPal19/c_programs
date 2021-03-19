#include <stdio.h>




void exchange(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
int partition (int arr[], int p, int r) 
{ 
    int x = arr[r];    
    int i = (p - 1);  
    for (int j = p; j <= r- 1; j++) 
    { 
        if (arr[j] < x) 
        { 
            i++;  
            exchange(&arr[i], &arr[j]); 
        } 
    } 
    exchange(&arr[i + 1], &arr[r]); 
    return (i + 1); 
} 

void quickSort(int arr[], int p, int r) 
{ 
    if (p < r) 
    {
        int q = partition(arr, p, r); 
        quickSort(arr, p, q - 1); 
        quickSort(arr, q + 1, r); 
    } 
} 
void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() 
{ 
    int n;
    int arr[30];
    printf("\nenter the number of elements in data : ");
    scanf("%d",&n);
    printf("\nenter the elements : ");
    for(int i=0;i<n;i++)
    {
        printf("enter the elements a[%d]: ",i);
        scanf("%d",&(arr[i]));
    }
    quickSort(arr, 0, n-1); 
    printf("Sorted array: \n"); 
    print(arr, n); 
    return 0; 
} 