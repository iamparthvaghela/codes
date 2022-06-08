#include <stdio.h>

int
main ()
{
  int n;
  printf ("Enter the number of elements\n");
  scanf ("%d", &n);
  int a[n];
  printf ("Enter the elements\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  printf ("Elements before bubble sort\n");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }

  int isSorted = 0;
  for (int i = 0; i < n - 1; i++)
    {
      isSorted = 1;
      for (int j = 0; j < n - 1 - i; j++)
	{
	  if (a[j] > a[j + 1])
	    {
	      int swap = a[j];
	      a[j] = a[j + 1];
	      a[j + 1] = swap;
	      isSorted = 0;
	    }
	}
      if (isSorted == 1)
	{
	  printf("\nAlready Sorted");
	  return 0;
	}
    }

  printf ("\nElements after bubble sort\n");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }

  return 0;
}

