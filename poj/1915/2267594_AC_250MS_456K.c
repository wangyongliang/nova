#include<stdio.h>
#define max 10000
int queen[10000],a[301][301];
int dx[]={-2,-2,-1,1,2, 2, 1,-1};
int dy[]={-1, 1, 2,2,1,-1,-2,-2};
int qstart ,qend,xx,yy,lenth;
int bfs()
{
	int k,qk,n=0,x,y;
	for(qk=0;qk!=qend;qk++,qk%=max)
	{
		if(x==xx&&y==yy)
						return n;
		if(queen[qk]==-1) 
			queen[qend]=-1,n++,qend=(qend+1)%max;
		else
		{
			x=queen[qk]/lenth;
			y=queen[qk]%lenth;
			for(k=0;k<8;k++)
			{
				if((x+dx[k]>=0&&x+dx[k]<lenth)&&(y+dy[k]>=0)&&(y+dy[k]<lenth))
				{

					if(a[x+dx[k]][y+dy[k]]==0||a[x+dx[k]][y+dy[k]]>n)
					{
						a[x+dx[k]][y+dy[k]]=n;
						queen[qend]=(x+dx[k])*lenth+y+dy[k];
						qend=(qend+1)%max;
					}
				}
			}
		}
	}
	
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&lenth);
		scanf("%d%d%d%d",&i,&j,&xx,&yy);
		queen[0]=i*lenth+j;
		qend=2;
		queen[1]=-1;
		for(i=0;i<lenth;i++)
		{
			for(j=0;j<lenth;j++)
			{
				a[i][j]=0;
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}