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

#define maxn 51000
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y)  (x)>(y)?(y):(x)
#define PS system("pause")
int a[maxn];
int b[maxn];
bool cmp(int x,int y)
{
    return a[x]>a[y];
}
bool flag[maxn];
int main()
{
    int n;
    int i,j;
    while(cin>>n)
    {
        for(i=0;i<n;i++) 
        {
            cin>>a[i];
            b[i]=i;
            flag[i]=1;
        }
        sort(b,b+n,cmp);
        for(i=0;i<n;i++)
        {
            if(flag[b[i]])
            {
                for(j=b[i]+1;j<n;j++)
                {
                    if(a[j]>=a[j-1]) break;
                    flag[j]=0;
                }
                for(j=b[i]-1;j>=0;j--)
                {
                    if(a[j]>=a[j+1])break;
                    flag[j]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(flag[i]) cout<<i+1<<endl;
        }
        
    }
    return 0;
}
