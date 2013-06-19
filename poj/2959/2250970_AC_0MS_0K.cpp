#include<stdio.h>
#include<math.h>
int main()
{
	double m,r,d,s;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&d,&r,&s);
		m=3.1415926/asin((s+r)/(d-r))-0.5;
		printf("%.0f\n",m);

	}
	return 0;
}