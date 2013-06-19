#include <cstdio>

int a[32002];
int level[15000];
int N;
int lowbit(int n)
{
 return n & (-n);
}

int Sum(int n)
{
 int result = 0;
 while(n != 0)
 {
  result += a[n];
  n -= lowbit(n);
 }
 return result;
}

void Update(int n)
{
 while(n <= 32001)
 {
  a[n]++;
  n += lowbit(n);
 }
}

int main(void)
{
 int x, y, i;
 scanf("%d", &N);
 i = N;
 while(i--)
 {
  scanf("%d%d", &x, &y);
  level[Sum(x+1)]++;
  Update(x+1);
 }

 for(i = 0; i < N; ++i)
  printf("%d\n", level[i]);
}
 
