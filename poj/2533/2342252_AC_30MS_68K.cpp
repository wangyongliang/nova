#include<stdio.h>
#define M 1002
int a[M],f[M];

int main()
{
int n,i,j,max;
while(scanf("%d",&n)!=EOF)
{
for(i=0;i<n;i++)
scanf("%d",&a[i]);
f[0]=1;
for(i=1;i<n;i++)
{
max=0;
for(j=0;j<i;j++) //从0到i中f最大的一个加上1
if((a[i]>a[j]) && (max<f[j]))
max=f[j];
f[i]=max+1;
}
max=0;
for(i=0;i<n;i++)
if(f[i]>max)
max=f[i];
printf("%d\n",max);
}
return 0;
}
