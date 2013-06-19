#include<stdio.h>
#include<algorithm>
using namespace std;
typedef __int64 int64;
struct node
{
	int x,y,z;
}a[100];
int ans[110],n,prime[30],pp=0,m=0;
int64 cnt;
bool flag[110]={0};
bool cmp(const node &x,const node &y)
{
	return x.x<y.x;
}
void dfs(int deep,int sum)
{
	int i,j,k;
	int64 tp=1;
	if(a[deep].x>sum)
	{
		int b[110]={0};
		for(i=0;i<m;i++)
		{
			if(flag[i])
			{
				b[a[i].y]=a[i].z;
			}
		}
		for(i=0;i<pp;i++)
		{
			for(j=0;j<b[prime[i]];j++) tp*=prime[i];
		}
		for(i=k=0;i<sum;i++) b[k++]=1;
		for(i=0;i<m;i++)
		{
			if(flag[i])
			{
				b[k++]=a[i].x;
			}
		}
		if(tp>cnt)
		{
			n=k;
			cnt=tp;
			for(i=0;i<k;i++)  ans[i]=b[i];
		}
		else if(tp==cnt)
		{
			for(i=0;i<k&&i<n;i++)
			{
				if(ans[i]<b[i])  return;
				if(ans[i]>b[i]) break;					
			}
			n=k;
			for(i=0;i<n;i++) ans[i]=b[i];
		}
	}
	else
	{
		for(i=deep;i<m;i++)
		{
			if(a[i].x<=sum) 
			{
				flag[i]=1;
				dfs(i+1,sum-a[i].x);
				flag[i]=0;
			}
		}
	}
}
int main()
{
	int i,j,k;
	for(i=2;i<100;i++)
	{
		if(flag[i]==0)
		{
			prime[pp++]=i;
			for(j=i+i;j<100;j+=i) flag[j]=1;
		}
	}
	for(i=2;i<100;i++)
	{
		if(!flag[i])
		{
			for(j=1,k=i;k<100;k*=i,j++)
			{
				a[m].x=k;
				a[m].y=i;
				a[m++].z=j;
			}
		}
	}
	sort(a,a+m,cmp);
	a[m].x=110;
	int sum,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&sum);
		for(cnt=i=0;i<m;i++) flag[i]=0;
		dfs(0,sum);
		printf("%I64d",cnt);
		for (j=1,i=0;i<n;i++){
			for (k=1;k<ans[i];k++)
				printf(" %d",j+k);
			printf(" %d",j);
			j+= ans[i];
		}
		printf("\n");
	}
	return 0;
}