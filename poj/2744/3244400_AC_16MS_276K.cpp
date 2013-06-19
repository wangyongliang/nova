#include<stdio.h>
double tp[10010];
double dp[110];
int main()
{
	int n,i,j,r,a[110];
	double b,v,e,f;
	while(scanf("%d",&n)&&n)
	{
		a[0]=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		scanf("%lf%d%lf%lf%lf",&b,&r,&v,&e,&f);
		tp[0]=0;
		for(i=1;i<=a[n-1];i++) 
		{
			if(i-1>=r) tp[i]=1.0/(v - e * (i -1- r)) ;
			else tp[i]=1.0/(v - f * (r - i+1));
			tp[i]+=tp[i-1];
		}
		double tp1;
		for(i=0;i<n;i++)
		{
			dp[i]=tp[a[i]];
			for(j=0;j<i;j++) 
			{
				tp1=dp[j]+b+tp[a[i]-a[j]];
				if(tp1<dp[i]) dp[i]=tp1;
			}
		}
		printf("%.4lf\n",dp[n-1]);
	}
	return 0;
}