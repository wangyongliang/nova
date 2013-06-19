#include<stdio.h>
#include<math.h>
#define g(x) ((x)>0?(x):-(x))

void f(int &x0,int &y0,int n)
{
		double x;
	int t,p,i;

		x=(sqrt(12*n-3)-3)/6;
		p=(int)x;
		if(3*p*p+3*p+1!=n)
		{ 
			t=n-(3*p*p+3*p+1);
			p++;
			x0=p-1;
			y0=0;
			while(t)
			{
				t--;
				y0++;
				for(i=1;i<=p-1&&t;i++,t--)x0--,y0++;

				for(i=1;i<=p&&t;i++,t--)x0--;		
				for(i=1;i<=p&&t;i++,t--)y0--;
				for(i=1;i<=p&&t;i++,t--)x0++,y0--;	
				for(i=1;i<=p&&t;i++,t--)x0++;
				for(i=1;i<=p&&t;i++,t--)y0++;
			}
		}
		else
			x0=p,y0=0;
}
int ans(int x0,int y0,int x1,int y1)
{
	int min;
	int t1,t2,t3;
	if(x0==x1) return g(y0-y1);
	if(y0==y1) return g(x0-x1);
	if(x0<x1)
	{
		min=x0;
		x0=x1;
		x1=min;
		min=y0;
		y0=y1;
		y1=min;
	}
	if(y0<y1)
	{
		t1=g(y0-y1)+g(x0-(y1-y0)-x1);
		t2=g(x0-x1)+g(y1-(y0+(x0-x1)));

	}
	else
	{
		t1=g(y0-y1)+g(x0-x1+(y0-y1));
		t2=g(y0-y1)+g(x0-x1);
	}
	if(t1<t2) return t1;
	return t2;
}
int main()
{
	int n,x0,y0,m;
	int x1,y1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		f(x0,y0,n);
		f(x1,y1,m);
		printf("The distance between cells %d and %d is %d.\n",n,m,ans(x0,y0,x1,y1));
	}
	return 0;
}
