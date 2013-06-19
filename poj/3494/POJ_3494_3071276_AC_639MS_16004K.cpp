#include<stdio.h>
#define maxn 2020
int a[maxn][maxn];
int b[maxn];
int n,m;
int ans;
void f()
{
	int q[2010],qq,c[2010][2],i;
	qq=0;
	for(i=0;i<m;i++)
	{
		while(qq&&b[q[qq-1]]>=b[i]) qq--;
		q[qq]=i;
		if(qq) c[i][0]=q[qq-1]+1;
		else c[i][0]=0;
		qq++;
	}
	qq=0;
	for(i=m-1;i>=0;i--)
	{
		while(qq&&b[q[qq-1]]>=b[i]) qq--;
		q[qq]=i;
		if(qq) c[i][1]=q[qq-1]-1;
		else c[i][1]=m-1;
		qq++;
	}
	int max=b[0]*(c[0][1]-c[0][0]+1);
	for(i=0;i<m;i++)
	{
		if(max<b[i]*(c[i][1]-c[i][0]+1)) max=b[i]*(c[i][1]-c[i][0]+1);
	}
	if(max>ans) ans=max;
}
int main()
{
	int i,j;
	int c[maxn];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) scanf("%d",&a[i][j]);
		}
		ans=0;
		for(i=0;i<m;i++) b[i]=a[0][i];
		f();
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]) b[j]++;
				else b[j]=0;
			}
			f();
		}
		printf("%d\n",ans);
	}
	return 0;
}