#include<stdio.h>
#include<algorithm>
using namespace std;
int w,h;
int a[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y)
{
	int i,temp;
	temp=a[x][y];
	a[x][y]=-1;
	for(i=0;i<4;i++)
	{
		if(x+dx[i]>=0&&x+dx[i]<w&&y+dy[i]>=0&&y+dy[i]<h&&a[x+dx[i]][y+dy[i]]==temp)
		{
			dfs(x+dx[i],y+dy[i]);
		}
	}
}
int  main()
{
	int i;
	int  n;
	int j;
	__int64 t;
	int x,y,xx,yy;
	int ans;
	while(scanf("%d%d",&w,&h)&&(w+h))
	{
		for(i=0;i<w;i++)
		{
			for(j=0;j<h;j++) a[i][j]=0;
		}
		scanf("%d",&n);
		t=1;
		while(n--)
		{
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			if(x>xx) swap(x,xx);
			if(y>yy) swap(y,yy);
			for(i=y;i<yy;i++)
			{
				for(j=x;j<xx;j++) a[i][j]+=t;
			}
			t*=2;
		}
		ans=0;
		for(i=0;i<w;i++)
		{
			for(j=0;j<h;j++)
			{
				if(a[i][j]!=-1)
				{
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
