#include<stdio.h>
int a[310][310];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
int q[1000000][2];
int flag[310][310];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	int i,j;
	int x,y,t,xx,yy;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<310;i++)
		{
			for(j=0;j<310;j++) 
			{
				a[i][j]=1000000;
				flag[i][j]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&t);
			a[x][y]=min(a[x][y],t);
			for(j=0;j<4;j++)
			{
				xx=x+dx[j];
				yy=y+dy[j];
				if(xx>=0&&xx<310&&yy>=0&&yy<310) a[xx][yy]=min(t,a[xx][yy]);
			}
		}
		int st=0;
		q[0][0]=0;
		q[0][1]=0;
		flag[0][0]=1;
		int en=1;
		while(st<en)
		{
			if(a[q[st][0]][q[st][1]]==1000000) break;
			x=q[st][0];
			y=q[st][1];
			for(i=0;i<4;i++)
			{
				xx=x+dx[i];
				yy=y+dy[i];
				if(xx>=0&&xx<310&&yy>=0&&yy<310&&flag[xx][yy]==0)
				{
					if(flag[x][y]<a[xx][yy]){
					flag[xx][yy]=flag[x][y]+1;
					q[en][0]=xx;
					q[en][1]=yy;
					en++;}
				}
			}
			st++;
		}
		if(st==en||(a[q[st][0]][q[st][1]]<1000000)) printf("-1\n");
		else printf("%d\n",flag[q[st][0]][q[st][1]]-1);
	}
	return 0;
}