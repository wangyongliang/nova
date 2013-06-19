#include<stdio.h>
#include<math.h>
double pi=acos(-1.0);

int main()
{
	double s;
	double h,r;
	while(scanf("%lf",&s)!=EOF)
	{
		double v=s*s/6.0/sqrt(2*s*pi);
		h=sqrt(2*s/pi);
		r=sqrt(3*v/pi/h);
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
}
