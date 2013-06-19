#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	double a,b;
	double pi,ans,ans2,ans1;
	double x,y;
	pi=acos(-1);
	while(scanf("%lf%lf",&a,&b)&&(a+b))
	{
		if(a>b) swap(a,b);
		ans=ans1=ans2=-1;
		if(b>(1+pi)*a)
		{
			ans=pi*a*a*a/4.0;
		}
		x=2*b/3.0;
		if(x<a/pi) ans1=pi*x*x*(b-x)/4.0;
		else
		{
			x=a/pi;
			ans1=pi*x*x*(b-x)/4.0;
		}
		x=b/(1+pi);
		if(x<a)ans2=pi*x*x*a/4.0;
		else ans2=-1;
		if(ans<ans1) ans=ans1;
		if(ans<ans2) ans=ans2;
		printf("%.3lf\n",ans);
	}
	return 0;
}