#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;
struct node{
	int x,y;
};
vector<node> a[30][30];

int croos(node p1,node p2,node p3){
	int dx1=p2.x-p1.x;
	int dy1=p2.y-p1.y;
	int dx2=p3.x-p1.x;
	int dy2=p3.y-p1.y;
	return dx1*dy2-dx2*dy1;
}
int check(node tp1,node tp2,node tp3,node tp4)
{
	int ans1=croos(tp1,tp3,tp2)*croos(tp1,tp2,tp4);
	int ans2=croos(tp3,tp1,tp4)*croos(tp3,tp4,tp2);
	if(ans1>0&&ans2>0) return 1;
	else return 0;
}
int peg[30][30];
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
bool vist[30][30];
void dfs(int x,int y)
{
	int i;
	for(i=0;i<a[x][y].size();i++){
		if(vist[a[x][y][i].x][a[x][y][i].y]==0){
			vist[a[x][y][i].x][a[x][y][i].y]=1;
			dfs(a[x][y][i].x,a[x][y][i].y);
		}
	}
}
int  main()
{
	int n,m;
	int i,j,k,ii,jj,kk;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				peg[i][j]=-1;
				a[i][j].clear();
			}
		}
		int flag=0;//0 is black,1 is white
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(peg[x][y]!=-1) printf("0\n");
			peg[x][y]=flag;
			for(i=0;i<9;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx>=0&&xx<=n&&yy>=0&&yy<=n&&peg[xx][yy]==flag)
				{
					node tp1,tp2;
					tp1.x=x;
					tp1.y=y;
					tp2.x=xx;
					tp2.y=yy;
					for(ii=MIN(x,xx);ii<=MAX(x,xx);ii++)
					{
						for(jj=MIN(y,yy);jj<=MAX(y,yy);jj++)
						{
						//	printf("%d\n",MAX(y,yy));
							node tp3;
							tp3.x=ii;
							tp3.y=jj;
							for(kk=0;kk<a[ii][jj].size();kk++)
							{
								node tp4=a[ii][jj][kk];
								if(check(tp1,tp2,tp3,tp4)) goto line;
							}
						}
					}
line:
					if(ii==MAX(x,xx)+1&&jj==MAX(y,yy)+1)
					{
						a[x][y].push_back(tp2);
						a[xx][yy].push_back(tp1);
					}
				}
			}
			flag=1-flag;
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++) vist[i][j]=0;
		}
		for(i=0;i<=n;i++)
		{
			if(peg[0][i]==0&&vist[0][i]==0) dfs(0,i);
		}
		for(i=0;i<=n;i++)
		{
			if(peg[n][i]==0&&vist[n][i]) break;
		}
		if(i<=n) printf("yes\n");
		else printf("no\n");

	}
	system("pause");
	return 0;
}

