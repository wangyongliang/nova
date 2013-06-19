#include <iostream.h>
#include <memory.h>
#include <stdio.h>

const int maxn = 101;

const int maxm = 10001;

int flag,N,M,dp[maxn][maxm];

void Dynamic(int T)
{
	int i,j,k,e,t;
	for (i=flag; i<=N; i++)
	{
		t = i * (i-1) / 2;
		for (j=1; j<=t; j++)
		{
			if (dp[i][j]) continue;
			for (k=0; k<=i; k++)
			{
				e = j-k*(i-k);
				if (e <0) break;
				if (e>=0 && dp[i-k][e]) 
				{
					dp[i][j]=1;break;
				}
			}
		}
	}
	flag = N+1;
	if (dp[N][M])
		printf("Case %d: %d lines with exactly %d crossings can cut the plane into %d pieces at most.\n"
		,T,N,M,N+M+1);
	else printf("Case %d: %d lines cannot make exactly %d crossings.\n",T,N,M);
	
}

int main()
{
	int i,T=0;
	flag = 2;
	for (i=0; i<=100; i++) dp[i][0]=1;
	while (scanf("%d%d",&N,&M))
	{
		if (N==0 && M==0) return 0;
		T++;
		if (N < flag)
		{
			if (dp[N][M])
				printf("Case %d: %d lines with exactly %d crossings can cut the plane into %d pieces at most.\n"
				,T,N,M,N+M+1);
			else printf("Case %d: %d lines cannot make exactly %d crossings.\n",T,N,M);
		}
		else
			Dynamic(T);
	}
	return 0;
}