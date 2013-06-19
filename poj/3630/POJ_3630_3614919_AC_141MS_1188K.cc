#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[10010][20];
int a[10010];
bool cmp(const int &x,const int &y)
{
    return strcmp(s[x],s[y])<0;
}
int f(int x,int y)
{
    int i;
    for(i=0;s[x][i];i++)
    {
        if(s[x][i]!=s[y][i]) return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n,i,j;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            a[i]=i;
            scanf("%s",s[i]);
        }
        sort(a,a+n,cmp);
        for(i=0;i<n-1;i++)
        {
            if(f(a[i],a[i+1])) break;
        }
        if(i==n-1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}