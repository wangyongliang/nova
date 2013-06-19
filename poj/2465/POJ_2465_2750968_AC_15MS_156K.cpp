

#include <stdio.h>
#define SIZE 105
#define MAX 0x7FFFFFF

int dp[SIZE][201];
int main()
{
	int i,j;
	for(i = 0; i < 105; i++)
		for(j = 0; j <= 200; j++)
			dp[i][j] = MAX;
	dp[0][100] = 0;
	int dis;
	i = 1;
	scanf("%d",&dis);
	int len,p,totlen,pre = 0;
	while(scanf("%d%d",&totlen,&p) != EOF)
	{
		if(totlen <= dis)
		{
			len = totlen - pre;
			for(j = len; j <= 200; j++)
				dp[i][j-len] = dp[i-1][j];
			for(j = 1; j <= 200; j++)
			{
				if(dp[i][j-1]+p < dp[i][j])
					dp[i][j] = dp[i][j-1]+p;
			}
		}
		pre += len;
		i++;
	}
	if(pre < dis)
	{
		len = dis-pre;
		for(j = len; j <= 200; j++)
			dp[i][j-len] = dp[i-1][j];
		i++;
	}
	int ans = MAX;
	for(j = 100; j <= 200; j++)
		if(dp[i-1][j] < ans)
			ans = dp[i-1][j];
	if(ans == MAX)
		printf("Impossible\n");
	else
		printf("%d\n",ans);
	return 0;
}