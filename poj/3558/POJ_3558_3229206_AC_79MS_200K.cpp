#include<stdio.h>
#include<math.h>
double ans[21];
double c[21][21]={0.0};
int main()
{
	int i,j;
	for(i=0;i<=20;i++) c[i][i]=1.0,c[i][0]=1.0;
	for(i=0;i<=20;i++)
	{
		for(j=0;j<i;j++)
		{
			c[i+1][j+1]=c[i][j];
			if(j+1<=i) c[i+1][j+1]+=c[i][j+1];
		}
	}
	double p;
	int n;
	while(scanf("%d%lf",&n,&p)!=EOF)
	{
	ans[1]=1;
	for(i=2;i<=n;i++)
	{
		ans[i]=0.0;
		for(j=0;j<=i-2;j++) ans[i]+=c[i-1][j]*ans[j+1]*pow(1-p,(j+1)*(i-j-1));
		ans[i]=1-ans[i];
	}
	printf("%.10lf\n",ans[n]);
}
	return 0;
}
