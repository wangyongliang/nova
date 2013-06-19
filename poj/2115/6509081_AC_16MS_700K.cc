#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef __int64 int64;
int64 gcd(int64 n,int64 m,int64 &x,int64 &y)
{
	int64 x0=1,y0=0,x1=0,y1=1;
	int64 r,q;
	r=(n%m+m)%m;
	q=(n-r)%m;
	x=0;
	y=1;
	while(r)
	{
		x=(x0-q*x1);
		y=(y0-q*y1);
		x0=x1;
		y0=y1;
		x1=x;
		y1=y;
		n=m;
		m=r;
		r=n%m;
		q=(n-r)/m;
	}
	return m;
}

int64 exgcd(int64 x,int64 &ansx,int64 y,int64 &ansy)
{
  //  cout<<x<<" "<<y<<endl;
  //  system("pause");
    if(x%y==0)
    {
        ansx=0;
        ansy=1;
        return y;
    }
    else
    {
        int64 tmpx,tmpy;
        int64 r=exgcd(y,tmpx,x%y,tmpy);
        ansx=tmpy;
        ansy=tmpx-tmpy*(x/y);
        return r;
    }
}
int main()
{
	int64 a,b,c,mod,x,y;
	int k;
	while(scanf("%I64d%I64d%I64d%d",&a,&b,&c,&k)&&(a+b+c+k))
	{
		a=b-a;		
		//b=1<<k;
b=pow(2,k);
	//	if(a<0) a+=b;
	//	a%=b;
		mod=exgcd(c,x,b,y);
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		if(a%mod||!c) printf("FOREVER\n");
		else
		{
			x*=a/mod;
			b/=mod;
			x=(x%b+b)%b;
			printf("%I64d\n",x);
		}
	}
	return 0;
}

