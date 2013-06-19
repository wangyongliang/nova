#include<stdio.h>
int main()
{
	int a[20][20];
	__int64 ans;
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(j&&a[i][j]*a[i][j-1]>0) ans+=a[i][j]*a[i][j-1];
				if(i&&a[i-1][j]*a[i][j]>0) ans+=a[i][j]*a[i-1][j];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}