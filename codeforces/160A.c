#include<stdio.h>
#include<stdlib.h>

void merge( int *array, int p, int mid, int q)
{
  int first[mid-p+1];
  int second[q-mid];
  int i,j,k;
  for(i=p, j=0; i<=mid; i++, j++)
  {
    first[j] = array[i];
  }
  for( i=mid+1, j=0; i<=q; i++, j++)
    second[j] = array[i];

  i =0;j =0;k = p;
  while(i<mid-p+1 && j<q-mid)
  {
    if(first[i] <= second[j])
    {
      array[k] = first[i];
      i++;
    }
    else
    {
      array[k] = second[j];
      j++;
    }
    k++;
  }

  while(i<mid-p+1)
  {
    array[k] = first[i];
    k++; i++;
  }
  
  while(j<q-mid)
  {
    array[k] = second[j];
    k++; j++;
  }
}


void merge_sort(int *array, int p, int q)
{
  if( q<= p ) return;
  int mid = (p+q)/2;
  merge_sort( array, p, mid);
  merge_sort( array, mid+1, q);

  merge(array, p, mid, q);
}



int main()
{

  int array[150];
  int n,i,p,q,sum=0;
  scanf("%d", &n);
  for(i= 1; i<=n; i++)
  {
    scanf("%d", &array[i]);
    sum += array[i];
  }
  merge_sort(array,1,n);
  p =0;
  q = sum;
  for(i=n;i>0;i--)
  {
    //printf("%d ", array[i]);
    p += array[i];
    q -= array[i];
    if(p>q)
      break;
  }
  printf("%d", n-i+1);
  return 0;

}
