#include<stdio.h>
int dx[]={0,1,0,1,1};
int dy[]={0,0,1,-1,1};
int flag[300]={0},n,m;
char s[20][20];
void dfs(int x,int y)
{
	int k=flag[s[x][y]];
	int xx=x+dx[k],yy=y+dy[k];
	char ch=s[x][y];
	s[x][y]='.';
	if(xx>=0&&x<n&&y>=0&&yy<m&&s[xx][yy]==ch) dfs(xx,yy);
}
int main()
{
	flag['|']=1;
	flag['-']=2;
	flag['/']=3;
	flag[92]=4;
	int t,i,j,flg;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%s",s[i]);
		flg=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(flag[s[i][j]])
				{
					flg++;
					dfs(i,j);
				}
			}
		}
		if(flg==1) printf("CORRECT\n");
		else printf("INCORRECT\n");
	}
	return 0;
}
