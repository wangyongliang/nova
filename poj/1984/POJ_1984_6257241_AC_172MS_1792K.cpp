#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct Q
{
    int x,y;
    int time;
    int id;
    int ans;
};
struct road
{
    int x,y;
    int len;
    char str[2];
};


bool cmp_time(const Q &x,const Q &y)
{
    return x.time<y.time;
}
bool cmp_id(const Q &x,const Q &y)
{
    return x.id<y.id;
}
#define maxn 100000
Q q[maxn];
road a[maxn];
int p[maxn][2];
int flag[maxn];

int find(int x)
{
    if(flag[x]==x) return x;
    else
    {
        
        int y=flag[x];
        flag[x]=find(flag[x]);
        p[x][0]+=p[y][0];
        p[x][1]+=p[y][1];
        return flag[x];
    }
}
int ABS(int x)
{
    if(x>0) return x;
    else return -x;
}
int main()
{
    int n,m,k;
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            flag[i]=i;
            p[i][0]=p[i][1]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%s",&a[i].x,&a[i].y,&a[i].len,&a[i].str);
        }   
        scanf("%d",&k);
        for(i=0;i<k;i++)     
        {
            scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].time);
            q[i].time--;
            q[i].id=i;
        }
        sort(q,q+k,cmp_time);
        j=0;
        for(i=0;i<m;i++)
        {
            int x=find(a[i].x);
            int y=find(a[i].y);
            if(x!=y)
            {
                p[x][0]=-p[a[i].x][0]+p[a[i].y][0];
                p[x][1]=-p[a[i].x][1]+p[a[i].y][1];
                if(a[i].str[0]=='N')
                {
                    flag[x]=y;
                    p[x][0]+=0;
                    p[x][1]+=-a[i].len;                   

                }
                else if(a[i].str[0]=='S')
                {
                    flag[x]=y;
                    p[x][0]+=0;
                    p[x][1]+=a[i].len;
                }
                else if(a[i].str[0]=='E')
                {
                    flag[x]=y;
                    p[x][0]+=-a[i].len;
                    p[x][1]+=0;
                }
                else 
                {
                    flag[x]=y;
                    p[x][0]+=a[i].len;
                    p[x][1]+=0;
                }
                
                
            }
            for(;j<k&&q[j].time<=i;j++)
            {
              //  cout<<j<<" :"<<q[j].x<<" "<<q[j].y<<" " <<q[j].time<<endl;

                x=find(q[j].x);
                y=find(q[j].y);
                if(x!=y)
                {
                    q[j].ans=-1;
                }
                else
                {
                    q[j].ans=ABS(p[q[j].x][0]-p[q[j].y][0])+ABS(p[q[j].x][1]-p[q[j].y][1]);
                }
               // cout<<q[j].ans<<endl;

            }

        }     
        sort(q,q+k,cmp_id);
        for(i=0;i<k;i++)
        {
           printf("%d\n",q[i].ans);
        }
    }
    return 0;
}
