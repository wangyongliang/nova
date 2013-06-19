#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	int z;
};
queue<node> q;
queue<int> p;
int a[1010][1010];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int main()
{
	int x,y,i,j,k,xx,yy,n;
	while(scanf("%d%d%d",&x,&y,&n)!=EOF)
	{
		x+=500;
		y+=500;
		for(i=0;i<1001;i++)
		{
			for(j=0;j<1001;j++) a[i][j]=0;
		}
		while(n--)
		{
			scanf("%d%d",&xx,&yy);
			xx+=500;
			yy+=500;
			a[xx][yy]=-1;
		}
		while(q.size()) q.pop();
		node tp;
		tp.x=tp.y=500;
		tp.z=1;
		a[500][500]=0;
		q.push(tp);
		a[x][y]=0;
		while(q.size()&&a[x][y]==0)
		{
			tp=q.front();
			q.pop();
			for(i=0;i<4;i++)
			{
				 xx=tp.x+dx[i];
				 yy=tp.y+dy[i];
				if(xx>=0&&xx<1001&&yy>=0&&yy<1001&&a[xx][yy]==0) 
				{
					a[xx][yy]=tp.z+1;
					node tp1;
					tp1.x=xx;
					tp1.y=yy;
					tp1.z=tp.z+1;
					q.push(tp1);
				}
			}
		}
		printf("%d\n",a[x][y]-1);
	}
	return 0;
}