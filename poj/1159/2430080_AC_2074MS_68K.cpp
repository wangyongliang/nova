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
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",str+1);
		for(i=n;i>0;i--)
			for(j=0;j<=n;j++)
			{
				if(i>=j) continue;
				if(str[i]==str[j])
					dp[i%2][j]=dp[(i+1)%2][j-1];
				else
					dp[i%2][j]=minimum(dp[(i+1)%2][j],dp[i%2][j-1])+1;
			}
		printf("%d\n",dp[1][n]);
	}
}