#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	double x,y,v,p;
}d[10];
double f(double x1,double y1,double v1,int i,double t)
{
	double x2,y2,vx,vy,p;
	p=d[i].p;
	vx=d[i].v*cos(p);
	vy=d[i].v*sin(p);
	x2=d[i].x+vx*t-x1;
	y2=d[i].y+vy*t-y1;
	double a,b,c;
	a=vx*vx+vy*vy-v1*v1;
	b=2*(x2*vx+y2*vy);
	c=x2*x2+y2*y2;
	double ans1= (-b+sqrt(b*b-4*a*c))/(2.0*a);
	double ans2= (-b-sqrt(b*b-4*a*c))/(2.0*a);
	return ans1>ans2?ans1:ans2;
}
int main()
{
	int b[10],i,j,n;
	double v,x,y,t,ans,tp;
	while(scanf("%d",&n)&&n)
	{
		scanf("%lf",&v);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&d[i].x,&d[i].y,&d[i].v,&d[i].p);
			b[i]=i;
		}
		ans=0;
		x=y=0.0;
		double best,last=0;
		for(i=0;i<n;i++)
		{
			ans+=f(x,y,v,b[i],ans);
			j=b[i];
			x=d[j].v*cos(d[j].p)*ans+d[j].x;
			y=d[j].y+d[j].v*sin(d[j].p)*ans;
			t=ans+sqrt(x*x+y*y)/d[j].v;
			if(t>last) last=t;
		}
		best=last;
		while(next_permutation(b,b+n))
		{
			tp=0;
			x=y=0.0;
			last=0;
			for(i=0;i<n;i++)
			{
				tp+=f(x,y,v,b[i],tp);
				j=b[i];
				x=d[j].x+d[j].v*cos(d[j].p)*tp;
				y=d[j].y+d[j].v*sin(d[j].p)*tp;
				t=tp+sqrt(x*x+y*y)/d[j].v;
				if(t>last) last=t;
			}
			if(last<best) best=last;
		}
		printf("%.0lf\n",best);
	}
	return 0;
}

