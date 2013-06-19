#include<stdio.h>
#define max 110
struct node
{
	int x,y;
	int fa,op;
}q[100000];
int a,b,c;
bool mp[max][max]={0};
char s[6][10]={"FILL(1)","POUR(1,2)","DROP(1)","FILL(2)","POUR(2,1)","DROP(2)"};
void find(int i)
{
	if(q[i].fa==-1)
	{
		puts(s[q[i].op]);
	}
	else
	{
		find(q[i].fa);
		puts(s[q[i].op]);
	}
}

void bfs()
{
	int st=0,en=3;
	int ans=1;
	int x,y;
	q[0].x=a;
	q[1].y=b;
	q[0].y=q[1].x=0;
	q[0].fa=q[1].fa=-1;
	q[0].op=0;
	q[1].op=3;
	q[2].x=-1;
	mp[a][0]=mp[0][b]=1;
	while(1)
	{
		if(q[st].x==c||q[st].y==c)
		{
			printf("%d\n",ans);
			find(st);
			return;
		}
		if(q[st].x==-1)
		{
			if(st+1==en)
			{
				printf("impossible\n");
				return;
			}
			else q[en++].x=-1,ans++;
		}
		else
		{
			x=a;
			y=q[st].y;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=0;
				q[en++].fa=st;
			}
			if(q[st].x<=b-q[st].y)
				x=0,y=q[st].y+q[st].x;
			else
				x=q[st].x-b+q[st].y,y=b;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=1;
				q[en++].fa=st;
			}
			x=0;
			y=q[st].y;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=2;
				q[en++].fa=st;
			}
			x=q[st].x;
			y=b;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=3;
				q[en++].fa=st;
			}
			if(q[st].y<=a-q[st].x) y=0,x=q[st].x+q[st].y;
			else y=q[st].y-a+q[st].x,x=a;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=4;
				q[en++].fa=st;
			}
			x=q[st].x;
			y=0;
			if(!mp[x][y])
			{
				mp[x][y]=1;
				q[en].x=x;
				q[en].y=y;
				q[en].op=5;
				q[en++].fa=st;
			}
		}
		st++;
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		bfs();
		for(i=0;i<=a;i++)
		{
			for(j=0;j<=b;j++) mp[i][j]=0;
		}
	}
	return 0;
}