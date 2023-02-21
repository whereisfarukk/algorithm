#include <bits/stdc++.h>
using namespace std;

void quickshort(int list[], int low , int high)
{
  int pivot, temp, i, j;
  if (low < high)
  {
    pivot = low;
    i = low;
    j = high;
    while (i < j)
    {
      while (list[i] <= list[pivot] && i <= high)
      {
        i++;
      }
      while (list[j] > list[pivot] && j >= low)
      {
        j--;
      }
      if (i < j)
      {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
    temp = list[j];
    list[j] = list[pivot];
    list[pivot] = temp;
    quickshort(list, low, j - 1);
    quickshort(list, j + 1, high);
  }
}
int main()
{
  int list[10];
  int n, i;


  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &list[i]);

  }
  quickshort(list, 0, n - 1);
  for(i=0;i<n;i++)
  {
      printf("%d ",list[i]);
  }
  
  return 0;
}
