#include <stdio.h>
#include <memory.h>

#define maxn 102

int arr[maxn],n,m;
double a[maxn][maxn];

void work()
{
	int i,j,k,t;
	double x;
	for (i=0; i<maxn; i++)
	{
		for (j=0; j<maxn; j++)
		{
			a[i][j] = 0.0;
		}
	}
	a[0][0] = 1;
	for (k=1; k<=m; k++)
	{
		for (i=0; i<n; i++)
		{
			if (arr[i]==1)
			{
				if (k<2) continue;
				else
					x = a[i][k-2];
			}
			else if (arr[i]==2) continue;
			else x = a[i][k-1];
			for (j=1; j<=6; j++)
			{
				t = i+j;
				if (t>n)
				{
					t = n-(t-n);
				}
				if (arr[t]==0 || arr[t] == 1)
				{
					a[t][k] += x / 6.0;
				}
				else if (arr[t] == 2)
				{
					a[0][k] += x / 6.0;
				}
			}
		}
	}
	double ret = 0.0;
	for (i=0; i<=m; i++)
		ret += a[n][i];
	printf("%.6lf\n",ret);
}

int main()
{
	int L,B,i,e;
	while (scanf("%d%d%d%d",&n,&m,&L,&B) && n+m+L+B)
	{
		memset(arr,0,sizeof(arr));
		for (i=0; i<L; i++)
		{
			scanf("%d",&e);
			arr[e] = 1;
		}
		for (i=0; i<B; i++)
		{
			scanf("%d",&e);
			arr[e] = 2;
		}
		work();
	}
	return 0;
}
