#include <stdio.h>
void main(void)
{
	int g[101][101];
	int t,n,k;
	int i,j,l;
	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&g[0][i]);
		for(j=1;j<n;j++)
			for(l=0;l<n-j;l++)
				g[j][l]=g[j-1][l+1]-g[j-1][l];
		for(l=1;l<=k;l++)
			g[n-1][l] = g[n-1][0];
		for(i=n-2;i>=0;i--)
			for(l=0;l<k;l++)
				g[i][n-i+l] = g[i][n-i+l-1] + g[i+1][n-i+l-1];
		for(i=0;i<k;i++)
			printf("%d ",g[0][i+n]);
		printf("\n");
	}
}