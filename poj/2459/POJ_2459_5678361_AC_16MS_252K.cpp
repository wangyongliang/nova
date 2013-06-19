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

int sum[maxn];
int n;
int d;
void insert(int x,int k)
{
    while(x<=d)
    {
        sum[x]+=k;
        x+=x&(-x);
    }
}
int find(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=sum[x];
        x-=x&(-x);
    }
    return ans;
}

int main()
{
    int c,f1,f2;
    int i,j;
    
    while(cin>>c>>f1>>f2>>d)
    {
        for(i=0;i<=d;i++) sum[i]=0;
        while(c--)
        {
            int x,y;
            cin>>x>>y;
            if(x>y) swap(x,y);
            insert(x,1);
            insert(y+1,-1);
        }

        f1-=f2;
        for(i=d;i>0&&f1;i--)
        {

            int k=find(i);
            if(k<=f1) f1-=k;
            else break;
            
        }
        cout<<i+1<<endl;

    }
    return 0;
}
