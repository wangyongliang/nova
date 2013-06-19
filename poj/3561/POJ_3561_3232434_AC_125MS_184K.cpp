#include<stdio.h>
int dx[]={0,1,0,1,1};
int dy[]={0,0,1,-1,1};
int flag[300]={0},n,m;
char s[20][20];
int main()
{
	flag['|']=1;flag['-']=2;
	flag['/']=3;flag[92]=4;
	int t,i,j,flg,x,y,xx,yy,k;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ch=getchar();
		for(i=0;i<n;i++) 
			for(j=0;j<=m;j++)s[i][j]=getchar();
		flg=0;
		for(i=0;i<n&&flg<=1;i++)
		{
			for(j=0;j<m&&flg<=1;j++)
			{
				if(flag[s[i][j]])
				{
					flg++; ch=s[i][j]; k=flag[s[i][j]];
					x=i,y=j;
					while(1)
					{
						s[x][y]='.';
						xx=x+dx[k];
						yy=y+dy[k];
						if(xx>=0&&x<n&&y>=0&&yy<m&&s[xx][yy]==ch) x=xx,y=yy;
						else break;
					}
				}
			}
		}
		if(flg==1) printf("CORRECT\n");
		else printf("INCORRECT\n");
	}
	return 0;
}
