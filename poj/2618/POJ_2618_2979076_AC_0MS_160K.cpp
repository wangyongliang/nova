#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={ 0,1,0,-1};
int f(int i,int j)
{
	int temp[6];
	int k;
	for(k=5;k>=0;k--)
	{
		temp[k]=i%10;
		i/=10;
	}
	k=temp[4];
	temp[4]=temp[(j+2)%4];
	temp[(j+2)%4]=temp[5];
	temp[5]=temp[j];
	temp[j]=k;
	int ans=0;
	for(k=0;k<6;k++)
	{
		ans=ans*10+temp[k];
	}
	return ans;
}
struct node
{
	int x,y,data;
}q[1000000];
int dir[20][20][4];
set<int> flag[20][20];
int main()
{
	int i,j,k,n,m,x,y,x1,y1,x2,y2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(k=0;k<4;k++) dir[i][j][k]=1;
			flag[i][j].clear();
		}
	}
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	char s[10];
	scanf("%s",s);
	while(scanf("%s",s)&&s[0]!='h')
	{
		j=atoi(s);
		scanf("%s",s);
		k=atoi(s);
//		swap(j,k);
		dir[j][k][2]=0;
		dir[j+1][k][0]=0;
	}
	while(scanf("%d%d",&j,&k)!=EOF)
	{
	//	swap(j,k);
		dir[j][k][1]=dir[j][k+1][3]=0;
	}
	int st=0,en=2,flg=0,ans=0;
	q[0].data=123456;
	q[0].x=x1;
	q[0].y=y1;
	flag[x1][y1].insert(123456);
	q[1].data=-1;
	while(st<en)
	{
		if(st==en-1&&q[st].data==-1) break;
		if(q[st].x==x2&&q[st].y==y2&&((q[st].data/10)%10==5))
		{
			flg=1;
			break;
		}
		if(q[st].data==-1)
		{
			q[en++].data=-1;
			ans++;
		}
		else
		{
			x=q[st].x;
			y=q[st].y;
			for(i=0;i<4;i++)
			{
				if(dir[x][y][i])
				{
					x1=x+dx[i];
					y1=y+dy[i];
					if((x1>0&&x1<=n)&&(y1>0&&y1<=m))
					{
						j=f(q[st].data,i);
						if(flag[x1][y1].find(j)==flag[x1][y1].end())
						{
							q[en].data=j;
							q[en].x=x1;
							q[en].y=y1;
							flag[x1][y1].insert(j);
							en++;
						}
					}
				}
			}
		}
		st++;
	}
	if(flg) printf("%d\n",ans);
	else printf("no\n");
	return 0;
}
