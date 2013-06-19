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

#define maxn 1100
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

char str[maxn][100];

int main()
{
    int i,j;
    int n,m;
    char tmp[100];
    int ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        for(i=0;i<n;i++) gets(str[i]);
        ans=0;
        while(m--)
        {
            gets(tmp)            ;
            for(i=0;i<n;i++)
            {
                for(j=0;tmp[j]&&str[i][j];j++)
                {
                    if(tmp[j]!=str[i][j]) break;
                }
                if(tmp[j]==0) break;
            }
            if(i<n) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
