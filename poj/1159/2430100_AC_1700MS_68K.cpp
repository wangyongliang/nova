#include<stdio.h>
#include<iostream.h>
//pku 3181
char str[5010];
short dp[2][5010]={0};

short minimum(short a,short b)
{
	return a<b?a:b;
}

void main()
{
	int n,i,j,flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		scanf("%s",str+1);
		for(i=n;i>0;i--,flag=1-flag)
			for(j=0;j<=n;j++)
			{
				if(i>=j) continue;
				if(str[i]==str[j])
					dp[flag][j]=dp[1-flag][j-1];
				else
					dp[flag][j]=minimum(dp[1-flag][j],dp[flag][j-1])+1;
			}
		printf("%d\n",dp[1-flag][n]);
	}
}
