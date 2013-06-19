//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//http://acm.pku.edu.cn/JudgeOnline/problem?id=2406
#include<stdio.h>
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
	char s[30][30];
	int n,m,i,j;
	int x,y;
	int q[100000][2];
	while(scanf("%d%d",&m,&n)&&(n+m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			for(j=0;j<s[i][j];j++)
			{
				if(s[i][j]=='@') 
				{
					x=i;
					y=j;
				}
			}
		}
		s[x][y]='#';
		q[0][0]=x;
		q[0][1]=y;
		i=0;
		j=1;
		int xx,yy;
		int cnt=0;
		while(i<j)
		{
			for(int k=0;k<4;k++)
			{
				xx=q[i][0]+dx[k];
				yy=q[i][1]+dy[k];
				if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='.')
				{
					cnt++;
					s[xx][yy]='#';
					q[j][0]=xx;
					q[j++][1]=yy;
				}
			}
			i++;
		}
		printf("%d\n",cnt+1);
	}
	return 0;
}