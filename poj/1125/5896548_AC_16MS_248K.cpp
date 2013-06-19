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

#define maxn 110
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

int a[maxn][maxn];
#define inf 1000000
int main()
{
    int i,j;
    int n,m;
    while (cin>>n)
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) a[i][j]=inf;
            a[i][i]=0;
        }
        for(i=0;i<n;i++)
        {
            cin>>j;
            while(j--)
            {
                int x,y;
                cin>>x>>y;
                x--;
                a[i][x]=MIN(a[i][x],y);
            }
        }
        int k;
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                if(a[i][k]<inf)
                {
                    for(j=0;j<n;j++)
                    {
                        if(a[k][j]==inf) continue;
                        if(a[i][k]+a[k][j]<a[i][j])
                        {
                            a[i][j]=a[i][k]+a[k][j];
                        }
                    }
                }
            }
        }
        int ans_num,ans_time;
        ans_time=inf+1;
        for(i=0;i<n;i++)
        {
            int tp_num=0;
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                tp_num=MAX(tp_num,a[i][j]);
            }
            if(ans_time>tp_num)
            {
                ans_num=i+1;
                ans_time=tp_num;
            }
        }
        if(ans_time==inf) cout<<"disjoint"<<endl;
        else cout<<ans_num<<" "<<ans_time<<endl;
    }
    return 0;
}
