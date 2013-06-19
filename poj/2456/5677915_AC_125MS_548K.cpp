#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

int a[maxn];
int n,c;
int check(int mid)
{
    int i;
    int last=a[0];
    int cnt=1;
    for(i=1;i<n&&cnt<c;i++)
    {
        if(a[i]-last>=mid)        
        {
            last=a[i];
            cnt++;
        }
    }
    if(cnt==c) return 1;
    else return 0;
}
int main()
{
    int min,max,mid;
    int i;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        min=0;
        max=a[n-1];
        while(min<max)
        {
            mid=(min+max+1)/2;
            if(check(mid)) min=mid;
            else max=mid-1;
        }
        printf("%d\n",min);
    }
    
    return 0;
}
