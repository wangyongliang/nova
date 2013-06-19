#include <stdio.h>
#include <string.h>

#define maxn 256

char s[maxn];
int dp[256],ch[maxn][maxn],ok[maxn][maxn],n;

int main()
{
	int i,j,k,l;
	scanf("%s",&s);
	n = strlen(s);
for(i=0;i<n;i++)
for(j=0;j<n;j++) ok[i][j]=0;
	for (i=0; i<n; i++)
		ok[i][i]=true,ch[i][i]=s[i];
	for (i=n-1; i>=0; i--)
	{
		for (j=i+1; j<n; j++)
		{
		//	if ((j-i+1)%2==0) continue;
			for (k=i+1; k<j; k++)
			{
				//if ((k-i)%2==0) continue;
				for (l=k; l<j; l++)
				{
					if (ok[i][k-1] && ok[l+1][j] && ok[k][l] && ch[i][k-1] == ch[l+1][j])
					{
						ok[i][j] = true, ch[i][j] = ch[k][l];
						k = j+1;
						break;
					}
				}
			}
		}
	}
	dp[0] = 1;
	dp[1] = 2;
	for (i=2; i<n; i++)
	{
		l = dp[i-1] + 1;
		if (ok[0][i])
		{
			dp[i] = 1;
			continue;
		}
		for (j=i; j>0; j--)
		{
			if (ok[j][i] && l > dp[j-1] + 1)
				l = dp[j-1] + 1;
		}
		dp[i] = l;
	}
	printf("%d\n",dp[n-1]);
	return 0;
}