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

#define maxn 60000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

vector<int> a[maxn];
int pre[maxn];

int  n,k;

queue<int >q;
int dfs(int i)
{
    while(q.size()) q.pop();
    q.push(1);
    pre[1]=1;
    while(q.size())
    {
        int i=q.front();
       // cout<<"i = "<<i<<endl;
        q.pop();
        for(int j=0;j<a[i].size();j++)
        {
            if(pre[a[i][j]]==-1)
            {
                pre[a[i][j]]=i;
                q.push(a[i][j]);
                if(a[i][j]==k) return 1;
            }
        }
    }
    return 0;
}
void print(int i,int deep)
{
    if(i==1)
    {
        printf("%d\n",deep);
        printf("1\n");
    }
    else 
    {
        print(pre[i],deep+1);
        printf("%d\n",i);
    }
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&k)!=EOF)    
    {
        for(i=1;i<=k;i++) 
        {
            a[i].clear();
            pre[i]=-1;
        }
        for(i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
        }
        pre[1]=1
        ;
        if(dfs(1))
        {
            print(k,1)            ;
        }
        else printf("-1\n");
    }
    return 0;
}
