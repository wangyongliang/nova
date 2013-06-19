#include<stdio.h>
#include<math.h>
int main()
{
	double vs,vr,r,c,w;
	int n;
	scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
	while(n--)
	{
		scanf("%lf",&w);
		printf("%.3lf\n\n",(r*c*w*vs)/sqrt(1+r*r*c*c*w*w));
	}
	return 0;
}