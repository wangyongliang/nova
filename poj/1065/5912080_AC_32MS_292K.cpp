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

#define maxn 10010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

struct node
{
    int x,y;
}a[maxn];
int cnt[maxn];
bool cmp(const node &x,const node &y)
{
    if(x.x==y.x) return x.y<y.y;
    else return x.x<y.x;
}

int main()
{
    int n;
    int i,j;
    int t;
    cin>>t;
    int m;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        sort(a,a+n,cmp);
        m=0;
        cnt[0]=a[0].y;
        m=1;
        for(i=1;i<n;i++)
        {
            int k=-1;
            for(j=0;j<m;j++)
            {
                if(cnt[j]<=a[i].y)
                {
                    if(k==-1||cnt[k]<cnt[j]) k=j;
                }
            }
            if(k!=-1)            cnt[k]=a[i].y;
            else
            {
                cnt[m++]=a[i].y;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
