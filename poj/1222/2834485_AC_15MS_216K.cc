

//pku 1468 1470 的其他方法

//pku 2559,3250 的共同点

//pku1690--pku1697

//pku 1222
#include<stdio.h>
int a[5][6];
int b[5][6];
int ans[5][6];
int dx[]={0,0,1,-1,};
int dy[]={1,-1,0,0};
void change(int x,int y)
{
	b[x][y]=1-b[x][y];
	int i;
	int xx,yy;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0&&xx<5&&yy>=0&&yy<6) b[xx][yy]=1-b[xx][yy];
	}
}
int check(int m)
{
	int i,j,k=m;
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			b[i][j]=a[i][j];
			ans[i][j]=0;
		}
	}
	for(i=0;i<6;i++)
	{
		ans[0][i]=k%2;
		k/=2;
		if(ans[0][i]) change(0,i);
	}
	for(i=1;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			if(b[i-1][j])
			{
				ans[i][j]=1;
				change(i,j);
			}
		}
	}
	for(i=0;i<6;i++)
	{
		if(b[4][i]) return 0;
	}
	return 1;
}
int main()
{
	int n,i,j;
	int t=1;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<6;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<64;i++)
		{
			if(check(i)) break;
		}
		printf("PUZZLE #%d\n",t++);
		for(i=0;i<5;i++)
		{
			printf("%d",ans[i][0]);
			for(j=1;j<6;j++) printf(" %d",ans[i][j]);
			printf("\n");
		}
	}
}
