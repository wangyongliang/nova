#include<stdio.h>
#include<algorithm>
using namespace std;
bool flag[1<<16]={0};
int prime[20000],k=0;
__int64 m,t;
__int64 abs(__int64 num)
{
	if(num>0) return num;
	else return -num;
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
int main()
{
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
		for(t=1;t*t<=m;t++)
		{
			if(m%t==0)
			{
				while(check(t));
				while(check(-t));
				while(check(m/t));
				while(check(-m/t));
			}
		}
        sort(b,b+bb);
        printf("%d\n",bb);
        for(i=0;i<bb;i++) 
        {
             printf("%I64d\n",b[i]);
        }
    }
    return 0;
}
