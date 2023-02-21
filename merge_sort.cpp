#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int lb, int mid, int ub)
{
  int i = lb;
  int j = mid + 1;
  int k = 0;
  int b[20], m, n;
  while (i <= mid && j <= ub)
  {
    if (a[i] <= a[j])
    {
      b[k] = a[i];
      i++; k++;
    }
    else
    {
      b[k] = a[j];
      j++; k++;
    }
  }
  if (i > mid)
  {
    while (j <= ub)
    {
      b[k] = a[j];
      j++; k++;
    }

  }
  else
  {
    while (i <= mid)
    {
      b[k] = a[i];
      k++; i++;
    }
  }
  for (i = lb; i <= ub; i++)
  {
    a[i] = b[i - lb];
  }
}
void mergeshort(int a[], int lb, int ub)
{
  if (lb < ub)
  {
    int mid = (lb + ub) / 2;
    mergeshort(a, lb, mid);
    mergeshort(a, mid + 1, ub);
    merge(a, lb, mid, ub);

  }

}
int main()
{
  int a[10], n;
  printf("how much element you want to sort");
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  mergeshort(a, 0, n - 1);
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  return 0;

}
