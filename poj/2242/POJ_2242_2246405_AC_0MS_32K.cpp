#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793
int main()
{
    double a,b,c;
	double x1,x2,x3,y1,y2,y3;
	double sinA,cosA,r;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		cosA=(b*b+c*c-a*a)/(2*b*c);
		sinA=sqrt(1-cosA*cosA);
		r=a/sinA;
		printf("%.2lf\n",pi*r);
	}
	return 0;
}
