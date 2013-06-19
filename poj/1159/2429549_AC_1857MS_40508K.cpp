#include<stdio.h>
#include<iostream.h>

char str[5010];
short dp[5010][5010]={0};

short minimum(short a,short b)
{
	return a<b?a:b;
}

void main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",str+1);
		for(i=n;i>0;i--)
			for(j=0;j<=n;j++)
			{
				if(i>=j) continue;
				if(str[i]==str[j])
					dp[i][j]=dp[i+1][j-1];
				else
					dp[i][j]=minimum(dp[i+1][j],dp[i][j-1])+1;
			}
		printf("%d\n",dp[1][n]);
	}
}
