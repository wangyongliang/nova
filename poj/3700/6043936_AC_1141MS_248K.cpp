#include<iostream>
using namespace std;
int m,n;
int ans;
int u[10],d[10];
int a[100];
int cnt;
/*
int abs(int x)
{
    if(x>0) return x;
    else return -x;
}
*/
void dfs(int deep)
{
    if(deep==cnt)
    {
        if(n+m<ans) ans=n+m;
    }
    else
    {
        int i;
        int index=-1;
        int flag1=0;
        int flag2=0;
        for(i=0;i<n;i++)        
        {
            if(a[deep]>u[i]&&(index==-1||abs(a[deep]-u[i])<abs(a[deep]-u[index])))
            {
                index=i;
            }
        }
        if(index!=-1)
        {
            int tmp=u[index];
            u[index]=a[deep];
            dfs(deep+1);
            u[index]=tmp;
            flag1=1;
        }
        index=-1;
        for(i=0;i<m;i++)
        {
            if(a[deep]<d[i]&&(index==-1||abs(a[deep]-d[i])<abs(a[deep]-d[index])))
            {
                index=i;
            }
        }
        if(index!=-1)
        {
            int tmp=d[index];
            d[index]=a[deep];
            dfs(deep+1);
            d[index]=tmp;
            flag2=1;
        }
        if(n+m+1>=ans) return;
        if(flag1==0)
        {
            u[n++]=a[deep];
            dfs(deep+1);
            n--;
        }
        if(flag2==0)
        {
            d[m++]=a[deep];
            dfs(deep+1);
            m--;
        }
    }
}
int main()
{
    int i;
    while(cin>>cnt)
    {
        if(cnt==0) return 0;
        for(i=0;i<cnt;i++){
            cin>>a[i];
        }
        ans=8;
        n=m=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
