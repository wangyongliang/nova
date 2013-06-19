#include<stdio.h>
char s[1000000];
int a[110][110];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool flag[110][110];
int n;
void f(int xx,int yy)
{
	int k;
	int x,y;
	for(k=0;k<4;k++)
	{
		x=xx+dx[k];
		y=yy+dy[k];
		if(x>0&&x<=n&&y>0&&y<=n&&flag[x][y]==0&&a[x][y]==a[xx][yy])
		{
			flag[x][y]=1;
			f(x,y);
		}
	}
}
int main()
{
	int i,j;
	int x,y;
	bool flg[110];
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=n;
				flag[i][j]=0;
			}
			flg[i]=0;
		}
		while(getchar()!='\n');
		for(i=1;i<n;i++)
		{
			gets(s);
			j=0;
			while(1)
			{
				while(s[j]==' ') j++;
				if(s[j]==0) break;
				x=y=0;
				while(s[j]>='0'&&s[j]<='9') x=x*10+s[j++]-'0';
				while(s[j]==' ') j++;
				while(s[j]>='0'&&s[j]<='9') y=y*10+s[j++]-'0';
				a[x][y]=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flag[i][j]==0)
				{
					if(flg[a[i][j]]) break;
					else
					{
						flg[a[i][j]]=1;
						flag[i][j]=1;
						f(i,j);
					}
				}
			}
			if(j<=n) break;
		}
		if(i<=n) printf("wrong\n");
		else printf("good\n");
	}
	return 0;
}