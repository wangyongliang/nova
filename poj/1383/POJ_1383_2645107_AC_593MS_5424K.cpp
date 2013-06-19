#include<stdio.h>
char s[1009][1009];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int xx,yy;
bool f(int i,int j)
{
	int ans=0;
	if(i-1>=0&&s[i-1][j]=='.') ans++;
	if(i+1<n&&s[i+1][j]=='.') ans++;
	if(j-1>=0&&s[i][j-1]=='.') ans++;
	if(j+1<m&&s[i][j+1]=='.') ans++;
	return ans==1;
}
struct node
{
	int x;
	int y;
}a[1000000];
int bfs(int p,int q)
{
	bool flag[1009][1009]={0};
	int i,j,k,x,y,ans=0;
	a[0].x=p;
	a[0].y=q;
	a[1].x=-1;
	j=0,k=2;
	flag[p][q]=1;
	while(1)
	{
		if(a[j].x==-1)
		{
			if(k==j+1) break;
			else
			{
				a[k].x=-1;
				k++;
				ans++;
			}
		}
		else
		{
			xx=a[j].x;
			yy=a[j].y;
			for(i=0;i<4;i++)
			{
				x=xx+dx[i];
				y=yy+dy[i];
				if((x>=0&&x<n)&&(y>=0&&y<m)&&s[x][y]=='.'&&!flag[x][y])
				{
					flag[x][y]=1;
					a[k].x=x;
					a[k].y=y;
					k++;
				}
			}
		}
		j++;
	}
	return ans;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++) scanf("%s",s[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;s[i][j];j++)
			{
				if(s[i][j]=='.')
				{
					if(f(i,j)) goto line;
				}
			}
		}
line:
		if(i==n&&j==m) printf("Maximum rope length is 0.\n");
		else
		{
			bfs(i,j);
			printf("Maximum rope length is %d.\n",bfs(xx,yy));
		}
	}
	return 0;
}