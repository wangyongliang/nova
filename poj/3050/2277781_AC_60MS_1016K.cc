#include<stdio.h>
int a[5][5];
char b[1000000]={'\0'};
void dfs(int deep,int x,int y,int n)
{
	n=n*10+a[x][y];
	if(deep>6) return;
	if(deep==6)
	{
		b[n]=1;
		return ;
	}
	if(x<4)dfs(deep+1,x+1,y,n);
	if(y<4)dfs(deep+1,x,y+1,n);
	if(x>0)dfs(deep+1,x-1,y,n);
	if(y>0)dfs(deep+1,x,y-1,n);
}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			dfs(1,i,j,0);
		}
	}
	for(j=i=0;i<1000000;i++)
	{
		if(b[i]) j++;
	}
	printf("%d\n",j);
	return 0;
}
