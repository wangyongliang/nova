#include<stdio.h>
#include<math.h>
void main()
{
	double sum,n,j;
	int m;
	double i;
	while(scanf("%d",&m)&&m)
	{
		m=(m-1960)/10;
		n=4*pow(2,m);
		sum=0;
		n=n*log(2.0);
		for(i=1;sum<=n;i++)
		{
			sum+=log(i);
		}
		printf("%.0lf\n",i-2);
	}
}