

//pku 1468 1470 的其他方法

//pku 2559,3250 的共同点

//pku1690--pku1697

#include<stdio.h>
#include<algorithm>
using namespace std;
#define inf 10000000
#define maxn 1010
struct node
{
	int x,y;
	char c;
	int time;
	int dir;
	int len;
} snake[30];
char s[maxn][maxn],ch;
int cnt;
int a[maxn][maxn][2]={0};
int n,t,num=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int change[4][3]={0,2,3,1,3,2,2,1,0,3,0,1};
bool cmp(const node &x,const node &y)
{
	return x.c<y.c;
}
int dfs(int x,int y)
{
	int i;
	int xx,yy;
	int flag=0,temp;
	a[x][y][0]=1;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&s[xx][yy]==ch&&a[xx][yy][0]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag) temp=dfs(xx,yy);
	a[x][y][0]=cnt;
	a[x][y][1]=ch-'a'+'A';
	cnt++;
	if(i%2==0) return i+1;
	else return i-1;
}
void move(int k)
{
	int i;
	int dir;
	int xx,yy;
	for(i=0;i<3;i++)
	{
		dir=change[snake[k].dir][i];
		xx=snake[k].x+dx[dir];
		yy=snake[k].y+dy[dir];
		if(xx>=0&&xx<n&&yy>=0&&yy<n)
		{
			if(a[xx][yy][1]<snake[k].c&&t>=a[xx][yy][0])
			{
				cnt++;
				snake[k].x=xx;
				snake[k].y=yy;
				snake[k].dir=dir;
				a[xx][yy][0]=t+snake[k].time;
				a[xx][yy][1]=snake[k].c;
				return ;
			}
			if(a[xx][yy][1]>=snake[k].c&&t>a[xx][yy][0])
			{			
				cnt++;
				snake[k].x=xx;
				snake[k].y=yy;
				snake[k].dir=dir;
				a[xx][yy][0]=t+snake[k].time;
				a[xx][yy][1]=snake[k].c;
				return ;
			}
		}
	}
	
}

void make_map(int x,int y,int tt)
{
	int i;
	int xx,yy;
	if(a[snake[num].x][snake[num].y][0]-tt>=snake[num].time-1) return ;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&a[xx][yy][0]==tt-1&&a[xx][yy][1]==a[x][y][1])
		{
			s[xx][yy]=a[x][y][1]-'A'+'a';
			make_map(xx,yy,a[xx][yy][0]);
			return;
		}
	}
}
int main()
{
	int m,i,j;
	scanf("%d%d",&n,&m);
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='#') a[i][j][0]=inf;
				if(s[i][j]>='A'&&s[i][j]<='Z')
				{
					snake[num].x=i;
					snake[num].y=j;
					snake[num].c=s[i][j];
					num++;
				}
			}
		}
		for(i=0;i<num;i++)
		{
			ch=snake[i].c-'A'+'a';
			cnt=1;
			snake[i].dir=dfs(snake[i].x,snake[i].y);
			snake[i].time=cnt-1;
		}
		sort(snake,snake+num,cmp);

		for(t=1;t<=m;t++)
		{
			cnt=0;
			for(i=0;i<num;i++)
			{
				move(i);

			}
			if(cnt==0) break;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) 
			{
				if(s[i][j]!='#') s[i][j]='.';
			}
		}
		for(num--;num>=0;num--)
		{
			s[snake[num].x][snake[num].y]=snake[num].c;
			make_map(snake[num].x,snake[num].y,a[snake[num].x][snake[num].y][0]);
		}
	//	printf("\n");
		for(i=0;i<n;i++) printf("%s\n",s[i]);
	}
	return 0;
}