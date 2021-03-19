#include <stdio.h>
#include <stdlib.h>

int *array, *checksum, *temp, i;

void append_checksum(int n, int m)
{

  for (i = 0; i <= m; i++)
  {
    *(array + n + i) = *(checksum + i); //complement the checksum to get final result
  }
}

void add(int *array1, int *array2, int m) //add two arrays of size m and stores the result in array2
{

  int carry, i, count;
  carry = 0;
  i = m - 1;
  while (i >= 0)
  {
    count = carry + *(array2 + i) + *(array1 + i);
    if (count == 1)
    {
      carry = 0;
      *(array2 + i) = 1;
    }
    else if (count == 2)
    {
      carry = 1;
      *(array2 + i) = 0;
    }
    i--;
  }
}

void generate_checksum(int n, int m, int *array)
{

  int i;

  for (i = 0; i < n / m; i++)
  {
    add(array + i * m, checksum, m);
  }

  printf("\n");
  printf("The checksum frame is : ");

  for (i = 0; i < m; i++)
  {
    *(checksum + i) = (*(checksum + i) + 1) % 2;
    printf("%d", *(checksum + i));
  }
}

void main()
{
  int n, m;

  printf("\nPlease enter the number of bits in data(multiple of 5) : ");
  scanf("%d", &n);

  array = (int *)calloc((n + 5), sizeof(int));
  checksum = (int *)calloc(5, sizeof(int));

  printf("Please enter the data bits\n");

  for (i = 0; i < n; i++)
  {
    scanf("%d", array + i);
  }

  generate_checksum(n, 5, array);

  append_checksum(n, 5);

  printf("\nThe final transimitting data is :");

  for (i = 0; i < n + 5; i++)
  {

    if (i % 5 == 0)
      printf(" ");
    printf("%d", *(array + i));
  }
  printf("\n");
}
