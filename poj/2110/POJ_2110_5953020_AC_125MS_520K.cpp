#include<iostream>
using namespace std;
#define maxn 500
int a[maxn][maxn];

bool flag[maxn][maxn];
int n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dfs(int x,int y)
{
    int i;
    flag[x][y]=0;
    if(x==n-1&&y==n-1) return 1;
    for(i=0;i<4;i++)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&flag[xx][yy])
        {
            if(dfs(xx,yy)) return 1;
        }
    }
    return 0;
}
int check(int min,int mid)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]>=min&&a[i][j]<=min+mid)
            {
                flag[i][j]=1;
            }
            else flag[i][j]=0;
        }
    }

    return dfs(0,0);
}
int main()
{
   // int n;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=110;
        for(i=0;i<=a[0][0];i++)
        {
            int min=0;
            int max=110;
            while(min<max)
            {
                int mid=(min+max)/2;
                if(check(i,mid))
                {
                    if(ans>mid) ans=mid;
                    max=mid;
                }
                else min=mid+1;
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
