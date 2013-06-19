#include<stdio.h> 
#include<math.h>
int a[2][400],b[400],path,n,k,xx,yy;
int dis(int x,int y,int x1, int y1)
{
	return abs(x-x1)+abs(y-y1);
}
void dfs(int x,int y,int deep,int sum)
{
	int i,j;
	if(deep==k)
	{
		j=dis(x,y,xx,yy);
		sum+=j;
		if(path>sum)path=sum;
	}
	else
	{
		if(sum<path)
		{
			for(i=0;i<k;i++)
			{
				if(b[i])
				{
					j=dis(a[0][i],a[1][i],x,y);
					b[i]=0;
					dfs(a[0][i],a[1][i],deep+1,sum+j);
					b[i]=1;
				}
			}
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	while(n--)
	{
		path=10000000;
		scanf("%*d%*d");
		scanf("%d%d",&xx,&yy);
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&a[0][i],&a[1][i]);
			b[i]=1;
		}
		dfs(xx,yy,0,0);
		printf("The shortest path has length %d\n",path);
	}
	return 0;
}
