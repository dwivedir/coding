#include<stdio.h>
#include<stdlib.h>

int log_2(int x)
{
  int y = 0;
  while(x >>= 1) ++y;
  return y;
}

int gpSum(int a, int n)
{
  int sum;
  sum = a * ( (1<< n) - 1);
  return sum;
}

int getN(int sum, int a)
{
  sum += a;
  sum /= a;
  return log_2(sum);
}

int main()
{
  int sum, n, nearSum;
  scanf("%d", &sum);
  n = getN(sum, 5);
  nearSum = gpSum(5,n);
  int length = 1<<n;
  //printf("n = %d sum= %d nearSUm = %d, length = %d\n",n, sum, nearSum, length); 
  if(nearSum == sum)
    puts("Howard");
  else if(nearSum + length >= sum)
    puts("Sheldon");
  else if(nearSum + 2* length >= sum)
    puts("Leonard");
  else if(nearSum + 3*length >= sum)
    puts("Penny");
  else if(nearSum + 4 * length >= sum)
    puts("Rajesh");
  else
    puts("Howard");

  return 0;
}
