#include<stdio.h>
int a[110][110],n;
bool c[110][110];
int b[110];
int dfs(int x,int deep)
{
	int i;
	int j=1;
	for(i=1;i<a[x][0];i++) 
	{
		if(b[a[x][i]]>=1&&b[a[x][i]]<deep-2) return 0;
		if(b[a[x][i]]==0) j=0;
	}
	if(j) 
		return 1;
	for(i=1;i<a[x][0];i++) if(b[a[x][i]]==0) b[a[x][i]]=1;
	for(i=1;i<=n;i++)
	{
		if(b[a[x][i]]==1)
		{
			b[a[x][i]]=deep;
			if(dfs(a[x][i],deep+1))
			{
				for(j=1;j<=n;j++) if(!b[j]) break;
				if(j>n) return 1;
			}
			b[a[x][i]]=1;
		}
	}
	for(i=1;i<a[x][i];i++)
	{
		if(b[a[x][i]]==1) b[a[x][i]]=0;
	}
	return 0;
}
int main()
{
	int i,j,e,k,flag=1;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&e);
		for(i=0;i<=n;i++)
		{
			a[i][0]=1,b[i]=0;
			for(j=0;j<=n;j++) c[i][j]=0;
		}
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&j,&k);
			if(c[j][k]==0)
			{
				c[j][k]=c[k][j]=1;
				a[j][a[j][0]++]=k;
				a[k][a[k][0]++]=j;
			}
		}
		for(j=0,i=1;i<=n;i++)
		{
			if(a[i][0]==2) 
			{
				j=i;
				break;
			}
		}
		if(j)
		{
			b[j]=3;
			if(dfs(j,4))
			{
				for(i=1;i<=n;i++) if(!b[i]) break;
				if(i>n)	printf("Graph %d is a caterpillar.\n",flag);
				else  printf("Graph %d is not a caterpillar.\n",flag);
			}
			else printf("Graph %d is not a caterpillar.\n",flag);
		}
		else printf("Graph %d is not a caterpillar.\n",flag);
		flag++;
	}
	return 0;
}