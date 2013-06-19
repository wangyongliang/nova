#include<stdio.h>
int a[4][4];
int  mod=10007;
int tp[33][4][4];
void init()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++) a[i][j]=0;
	}
	a[0][0]=2;
	a[2][0]=1;
	a[1][0]=1;

	a[0][1]=1;
	a[1][1]=2;
	a[3][1]=1;

	a[0][2]=1;
	a[2][2]=2;
	a[3][2]=1;

	a[1][3]=1;
	a[2][3]=1;
	a[3][3]=2;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			tp[1][i][j]=a[i][j];
		}
	}
	for(i=2;i<33;i++)
	{
		for(j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				tp[i][j][k]=0;
				for(int l=0;l<4;l++)
				{
					tp[i][j][k]+=tp[i-1][j][l]*tp[i-1][l][k];
					tp[i][j][k]%=mod;
				}
			}
		}
	}
	return ;
}
int dp[]={2,1,1,0};
int ans[4][4];

int main()
{
	init();
	int n;
	int t;
	scanf("%d",&t);
	int i,j,k;
	int tq[4][4];
	while(t--)
	{
		scanf("%d",&n);
		n--;
		//if()
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++) ans[i][j]=0;
			ans[i][i]=1;
		}
		for(i=1;n;i++,n/=2)
		{
			if(n%2)
			{
				for(j=0;j<4;j++)
				{
					for(k=0;k<4;k++)
					{
						tq[j][k]=0;
						for(int l=0;l<4;l++) tq[j][k]=(tq[j][k]+ans[j][l]*tp[i][l][k])%mod;
					}
				}
				for(j=0;j<4;j++)
				{
					for(k=0;k<4;k++) ans[j][k]=tq[j][k];
				}
			}
		}
		int res=0;
		for(i=0;i<4;i++) res=(res+dp[i]*ans[i][0])%mod;
		printf("%d\n",res);

	}
	return 0;
}
