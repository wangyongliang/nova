#include<stdio.h>
#include<algorithm>
using namespace std;
bool flag[1<<16]={0};
int prime[20000],k=0;
__int64 m;
__int64 abs(__int64 num)
{
	if(num>0) return num;
	else return -num;
}
__int64 pow(int num,int k)
{
	__int64 ans=1;
	while(k--) ans*=num;
	return ans;
}
void init()
{
    int i,j;
	prime[k++]=2;
	for(i=2;i<1<<16;i+=2) flag[i]=1;
    for(i=3;i<=1<<8;i+=2)
    {
        if(!flag[i])
        {
            for(j=i*i;j<1<<16;j+=i*2)
            {
                flag[j]=1;
            }
            prime[k++]=i;
        }
    }
    for(;i<=1<<16;i+=2)
    {
        if(!flag[i]) prime[k++]=i;
    }
}
__int64 p[110], b[200];
int a[40][2],bb,n;
int check(__int64 num)
{
	int i;
	__int64 mod,temp[100];
	mod=p[0];
	for(i=0;i<n;i++)
	{
		temp[i]=mod;
		mod=p[i+1]-num*mod;
	}
	if(mod==0)
	{
		for(i=0;i<n;i++) p[i]=temp[i];
		b[bb++]=-num;
		n--;
	}
	if(mod==0) return 1;
	else return 0;
}
void dfs(int deep,int j,__int64 ans)
{
    __int64 temp,i;
    if(deep==j)
    {
		while(check(ans));
		while(check(-ans));
    }
    else
    {
       for(i=0;i<=a[deep][1];i++)       
       {
          temp=ans*pow(a[deep][0],i);
          dfs(deep+1,j,temp);
       }
    }
}
int main()
{
    init();
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        p[0]=1;
        for(i=1;i<=n;i++)
        {
           scanf("%I64d",&p[i]);
        }
        bb=0;
        while(p[n]==0&&n)
        {
           b[bb++]=0;
           n--;
        }
        if(p[n]>0) m=p[n];
        else m=-p[n];
        for(j=i=0;prime[i]*prime[i]<=m&&i<k;i++)
        {
            if(m%prime[i]==0)          
            {
               a[j][0]=prime[i];
               a[j][1]=0;
               while(m%prime[i]==0)
               {
                  a[j][1]++;
                  m/=prime[i];
               }
               j++;
            }
        }
        if(m!=1) a[j][0]=m,a[j++][1]=1;
		m=p[n];
        dfs(0,j,1);
        sort(b,b+bb);
        printf("%d\n",bb);
        for(i=0;i<bb;i++) 
        {
             printf("%I64d\n",b[i]);
        }
    }
    return 0;
}
