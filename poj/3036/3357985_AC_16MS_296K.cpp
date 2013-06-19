#include<stdio.h>
int dp[32][32][30];
int dx[]={0,0,1,-1,1,-1};
int dy[]={1,-1,0,0,-1,1};
int main()
{
	int t,n,i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++)
			{
				for(k=0;k<30;k++) dp[i][j][k]=0;
			}
		}
		dp[15][15][0]=1;
		int x,y;
		for(i=0;i<n;i++)
		{
			for(j=0;j<30;j++)
			{
				for(k=0;k<30;k++)
				{
					for(l=0;l<6;l++)
					{
						x=j+dx[l];
						y=k+dy[l];
						dp[x][y][i+1]+=dp[j][k][i];
					}
				}
			}
		}
		printf("%d\n",dp[15][15][n]);
	}
	return 0;

}