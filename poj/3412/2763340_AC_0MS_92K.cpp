#include<stdio.h>
#include<math.h>
double a[110];
int main()
{
	int n,i;
	double x,y,x1,y1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%lf",&a[i]);
		scanf("%lf",&x);
		x1=x;
		for(i=1;i<n;i++)
		{
			y1=a[i-1]*sin(x)/a[i];
			if(y1>1) break;
			else  x=asin(y1);
		}
		if(i<n) printf("NO\n");
		else 
			printf("%.4lf\n",x);
	}
	return 0;
}