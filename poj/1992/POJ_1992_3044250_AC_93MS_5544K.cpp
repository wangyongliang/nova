#include<stdio.h>
char a[1000+100][1000+100];
int dp[1100][1100];
int main()
{
	int r,s,i,j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&s);
		for(i=0;i<r;i++) scanf("%s",a[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<s;j++) dp[i][j]=0;
		}
		dp[0][0]=1;
		for(i=0;i<r;i++)
		{
			for(j=0;j<s;j++)
			{
				if(a[i][j]=='.'){
				if(i&&a[i-1][j]=='.') dp[i][j]+=dp[i-1][j];
				if(j&&a[i][j-1]=='.') dp[i][j]+=dp[i][j-1];
				}
			}
		}
		printf("Existuje %d ruznych cest.\n",dp[r-1][s-1]);
	}
	return 0;
}