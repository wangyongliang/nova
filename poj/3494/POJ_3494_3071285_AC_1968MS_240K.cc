#include<stdio.h>
#define maxn 2020
int b[maxn];
int n,m;
int ans;
void f()
{
	int q[2010],qq,c[2010][2],k;
	qq=0;
	for(k=0;k<m;k++)
	{
		while(qq&&b[q[qq-1]]>=b[k]) qq--;
		q[qq]=k;
		if(qq) c[k][0]=q[qq-1]+1;
		else c[k][0]=0;
		qq++;
	}
	qq=0;
	for(k=m-1;k>=0;k--)
	{
		while(qq&&b[q[qq-1]]>=b[k]) qq--;
		q[qq]=k;
		if(qq) c[k][1]=q[qq-1]-1;
		else c[k][1]=m-1;
		qq++;
	}
	int max=b[0]*(c[0][1]-c[0][0]+1);
	for(k=0;k<m;k++)
	{
		if(max<b[k]*(c[k][1]-c[k][0]+1)) max=b[k]*(c[k][1]-c[k][0]+1);
	}
	if(max>ans) ans=max;
}
int main()
{
	int i,j,x;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		for(i=0;i<m;i++) scanf("%d",&b[i]);
		f();
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				if(x) b[j]++;
				else b[j]=0;
			}
			f();
		}
		printf("%d\n",ans);
	}
	return 0;
}