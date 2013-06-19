#include <stdio.h>
#include <math.h>
int main()
{
 int a[1000];
 long n;
 long count;
 int temp;
 int i,j,l,t,p,p1;
 while(scanf("%ld",&n)&&n)
 {
  l=0;
  temp=(int)sqrt(n);
  for(i=2;i<=temp;i++)
  {
   if(n%i==0) a[l++]=i;
  }
  t=l;
  for(i=l-1;i>=0;i--)
  {
   a[t++]=n/a[i];
  }
  for(i=0;i<t-1;i++)
  {
   for(j=i+1;j<t;j++)
   {
    if(a[j]%a[i]==0&&a[i]!=-1&&a[j]!=-1) a[j]=-1;
   }
  }
  count=1;
  p=0;
  for(i=0;i<t;i++)
  {
   p=1;
   if(a[i]==-1) continue;
   p1=0;
      while(n%a[i]==0)
   {
    n=n/a[i];
    p1++;
   }
   count*=(pow(a[i],p1-1)*(a[i]-1));
  }
  if(p==0) printf("%ld\n",n-1);
  else printf("%ld\n",count); 
 }
 return 0;
}