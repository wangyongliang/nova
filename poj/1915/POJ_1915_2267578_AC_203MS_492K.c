#include<stdio.h>
#define max 10000
int queen[10000][2],a[301][301];
int dx[]={-2,-2,-1,1,2, 2, 1,-1};
int dy[]={-1, 1, 2,2,1,-1,-2,-2};
int qstart ,qend,xx,yy,lenth;
int bfs()
{
	int k,qk,n=0;
	for(qk=0;qk!=qend;qk++,qk%=max)
	{
		if(queen[qk][0]==xx&&queen[qk][1]==yy)
						return n;
		if(queen[qk][0]==-1) 
		{
			queen[qend][0]=-1,n++,qend++,qend%=max;
		}
		else
		{
			for(k=0;k<8;k++)
			{
				if((queen[qk][0]+dx[k]>=0&&queen[qk][0]+dx[k]<lenth)&&(queen[qk][1]+dy[k]>=0)&&(queen[qk][1]+dy[k]<lenth))
				{

					if(a[queen[qk][0]+dx[k]][queen[qk][1]+dy[k]]==0||a[queen[qk][0]+dx[k]][queen[qk][1]+dy[k]]>n)
					{
						a[queen[qk][0]+dx[k]][queen[qk][1]+dy[k]]=n;
						queen[qend][0]=queen[qk][0]+dx[k];
						queen[qend][1]=queen[qk][1]+dy[k];
						qend++;
						qend%=max;
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
		scanf("%d%d%d%d",&queen[0][0],&queen[0][1],&xx,&yy);
		qend=2;
		queen[1][0]=-1;
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