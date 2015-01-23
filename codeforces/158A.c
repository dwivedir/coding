#include<stdio.h>
#include<stdlib.h>

int binary(int array[], int p, int q, int x)
{
  if(q<p) return -1;
  else if(q == p+1)
  {
    if(array[q] == x) return q;
    else if (array[p] == x) return p;
    else return -1;
  }
  else if(p == q)
  {
    if( array[p] == x)
      return p;
    else
      return -1;
  }

  int mid = (p+q)/2;
  if ( array[mid] >=  x)
    return binary(array, mid, q, x);
  else return binary(array, p, mid-1, x);
}

int binary_for_0(int array[], int p, int q)
{
  if(q<p) return -1;
  else if(q == p+1)
  {
    if(array[q] > 0) return q;
    else if (array[p] > 0) return p;
    else return -1;
  }
  else if(p == q)
  {
    if (array[p] > 0) return p;
    else return -1;
  }

  int mid = (p+q)/2;
  if( array[mid] == 0)
    return binary_for_0(array, p, mid-1);
  else if(array[mid] > 0)
    return binary_for_0(array, mid, q);
}
int main()
{
  int i,array[100],x,n,k;
  scanf("%d %d", &n, &k);
  for( i=1; i<=n; i++)
    scanf("%d", &array[i]);

  x = array[k];
  if( x == 0 )
    x = binary_for_0(array, 1, n);
  else
    x = binary(array,1,n,x);
  if(x == -1)
    printf("0");
  else
    printf("%d",x);

  return 0;
  
}
