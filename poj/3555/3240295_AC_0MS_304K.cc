#include<stdio.h>
#include<math.h>
int main()
{
	double h,r,h1,d1,d2,h2,d,n;
	double s1,s2,s3;
	double m,tp,pi;
	pi=acos(-1);
	double ans,x1,x2;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&h,&r,&d1,&h1,&d2,&h2,&d,&n)!=EOF)
	{
		s1=pi*r*r;
		s2=n*n;
		s3=s1-s2;
		m=d*n*n*n;
		if(d>=d1&&d>=d2)
		{
			ans=s1*(h1+h2)/s3;
			if(ans>n) ans=((s1*(h1+h2)+n*n*n))/s1;
		}
		else if(d<d1&&d>=d2)
		{
			x1=s1*h1/s3;
			x2=s1*h2/s3;
			if(x2+x1>=n) x2=n-x1;
			tp=s2*(x1*d1+x2*d2);
			if(tp>=m)
			{
				x2=s1*h2/s3;
				tp=x2*s2*d2+(n-x2)*s2*d1;
				if(tp>=m)
				{
					x1=(m-s2*x2*d2)/s2/d1;
					ans=(s1*(h1+h2)+(x1+x2)*s2)/s1;
				}
				else ans=(s1*(h1+h2)+n*s2)/s1;
			}
			else 
			{
			//	x1=n-x2-x1;
				ans=(s1*(h1+h2)+(x1+x2)*s2)/s1;
			}
		}
		else
		{
			x1=s1*h2/s3;
			x2=s1*h1/s3;
			if(s2*x1*d2>=m)
			{
				x1=m/s2/d2;
				ans=(s1*(h1+h2)+x1*s2)/s1;
			}
			else 
			{
				x2=(m-s2*x1*d2)/s2/d1;
				if(s1*h1<=s3*x2) ans=s1*(h1+h2)/s3;
				else ans=(s1*(h1+h2)+(x1+x2)*s2)/s1;
			}
		}
		if(ans>h) ans=h;
		printf("%.3lf\n",ans);
	}
	return 0;
}