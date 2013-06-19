#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 401000
int st[maxn];
int getmin(int s,int m)
{
int j,a,b,k,flag;
for (j=0;j<m;++j)
   st[j+m]=st[j];
a=s,b=s+1,k=0,flag=1;
if (b>=m)
   return a;
while (flag)
{
   if(st[a+k]==st[b+k])
   {
    ++k;
    if (k>=m) break;
   }
   else if (st[a+k]<st[b+k])
   {
    b=b+k+1;
    if (b<=a) b=a+1;
    if (b>=m) break;
    k=0;
   }
   else 
   {
    a=a+k+1;
    if (b>=a) a=b+1;
    if (a>=m) break;
    k=0;
   }
}
if (a<b) return a;
else return b;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=n-1;i>=0;i--) scanf("%d",&st[i]);
    i=getmin(2,n);
    //printf("i= %d\n",i);
    for(j=i;j<n;j++) printf("%d\n",st[j]);
    n=i;
    i=getmin(1,n);
   // printf("i= %d\n",i);
    for(j=i;j<n;j++) printf("%d\n",st[j]);
    n=i;
    for(j=0;j<n;j++) printf("%d\n",st[j]);
    return 0;
}

