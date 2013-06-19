#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 401000
int s[maxn];
int getmin(int st,int m)
{
    int i,j,a,b;
    for(j=0,i=m;j<m;j++,i++) s[j+m]=s[j];
    int k=0;
    a=st;
    b=st+1;
if(b>=m) return a;
    while(1)
    {
        if(s[a+k]==s[b+k])
        {
            k++;
            if(k>=m) break;
        }
        else if(s[a+k]>s[b+k])
        {
            a+=k+1;
            if(a<=b) a=b+1;
            if(a>=m) break;
            k=0;
        }
        else 
        {
            b+=k+1;
            if(b<=a) b=a+1;
            if(b>=m) break;
            k=0;
        }
    }
if(a<b) return a;
else return b;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&s[i]);
    reverse(s,s+n);
    i=getmin(2,n);
    //printf("i= %d\n",i);
    for(j=i;j<n;j++) printf("%d\n",s[j]);
    n=i;
    i=getmin(1,n);
   // printf("i= %d\n",i);
    for(j=i;j<n;j++) printf("%d\n",s[j]);
    n=i;
    for(j=0;j<n;j++) printf("%d\n",s[j]);
  //  while(1);
    return 0;
}

