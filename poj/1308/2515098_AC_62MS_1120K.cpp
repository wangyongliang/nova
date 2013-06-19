#include<stdio.h>
#define size 1009
bool a[size][size];
int flag[size];
bool flg[size];
int dfs(int k)
{
	int i;
	if(flag[k]) return 0;
	flag[k]=1;
	for(i=1;i<size;i++)
	{
		if(a[k][i])
		{
			if(flag[i]) return 0;
			if(dfs(i)==0) return 0;
		}
	}
	return 1;
}
int main()
{
	int x,y,t=1;
	int max,i,j;
	while(scanf("%d%d",&x,&y)&&x!=-1)
	{
		if(x==0&&y==0)
		{
			printf("Case %d is a tree.\n",t++);
			continue;
		}
		for(i=0;i<size;i++)
		{
			flag[i]=0;
			flg[i]=0;
			for(j=0;j<size;j++) a[i][j]=0;
		}
		a[x][y]=1;
		max=x>y?x:y;
		flag[y]++;
		flg[x]=1;
		flg[y]=1;
		while(scanf("%d%d",&x,&y)&&(x+y))
		{
	//		if(x==y) goto line;
			a[x][y]=1;
			flag[y]++;
			flg[x]=1;
			flg[y]=1;
			max=x>max?x:max;
			max=y>max?y:max;
		}
		for(i=1,x=max,y=0;i<=max;i++)
		{
			if(flg[i])
			{
				if(flag[i]>1) break;
				if(flag[i]==0) x=i,y++;
			}
		}
		if(flag[x]||y>1||flag[i]>1)
			printf("Case %d is not a tree.\n",t);
		else
		{
			for(j=0;j<=max;j++) flag[j]=0;
			if(dfs(x))
			{
				for(i=1;i<=max;i++)
				{
					if(flg[i]==1&&flag[i]==0) break;
				}
				if(flag[i]==0&&i<=max) printf("Case %d is not a tree.\n",t);
				else 	printf("Case %d is a tree.\n",t);
			}
			else  printf("Case %d is not a tree.\n",t);
		}
		t++;
	}
	return 0;
}
