#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a[10],i,j,n;
  printf("enter the number of element\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {

        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;

      }
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}
