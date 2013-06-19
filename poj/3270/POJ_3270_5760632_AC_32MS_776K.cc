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
bool flag[maxn];
int a[maxn];
int index[maxn];
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int n;
    long long ans=0;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=0;i<n;i++)
        
        {
            index[i]=i;
            scanf("%d",&a[i]);
            flag[i]=0;
        }
        sort(index,index+n,cmp);
        for(i=0;i<n;i++)
        {
            if(index[i]==i)continue;
            if(flag[i]) continue;
            int now=i;
            int min=a[i];
            int cnt=0;
            int tp=0;
            while(flag[now]==0)
            {
                flag[now]=1;
                cnt++;
                tp+=a[now];
                if(min>a[now]) min=a[now];
                now=index[now];
            }
            tp-=min;
            if(tp+(cnt-1)*min<tp+(cnt-1)*a[index[0]]+2*(min+a[index[0]]))
            {
                ans+=tp+(cnt-1)*min;
            }
            else ans+=tp+(cnt-1)*a[index[0]]+2*(min+a[index[0]]);
            
        }
        cout<<ans<<endl;
    }
    return 0;
}
