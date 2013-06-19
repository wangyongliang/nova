#include<stdio.h>
typedef __int64 int64;
int64 exgcd(int64 m,int64 & x,int64 n,int64 & y)  // Extend Euclid 
{	int64 x1,y1,x0,y0;
	x0=1;y0=0;
	x1=0;y1=1;
          int64 r=(m%n+n)%n;
	int64 q=(m-r)/n;
	x=0;y=1;
	while(r)
	{  x=x0-q*x1;y=y0-q*y1; x0=x1;y0=y1;
	    x1=x;y1=y;
	    m=n;n=r;r=m%n;
	   q=(m-r)/n;
	}
	return n;
}
int main()
{
	int64 d,m,r,l,mod,x,y,dx,tp,ans,tp2,tp3;
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&m,&d,&l,&r);
		mod=exgcd(d,x,m,y);
		if(r>=m) r=m-1;
		if(l>=m||l>r) 
		{
			printf("-1\n");
			continue;
		}
		y=m/mod;
	//	x=(x%y+y)%y;
		dx=r/mod-l/mod;
	//	if(dx<1) printf("-1\n");
	//	else
		{
			if(dx>=1000000)
			{
				ans=l/d+(l%d!=0);
				y=(ans%m)*(d%m);
				y%=m;
				d%=m;
				while(1)
				{
					if(y>=l&&y<=r) break;
					ans++;
					y+=d;
					while(y>=m) y-=m;
				}
			}
			else
			{
				ans=0x7fffffffffffffff;
				dx=mod/d+(mod%d!=0);
				tp2=m/mod;
				for(y=l/mod+(l%mod!=0);y*mod<=r;y++)
				{
					if(y==1107)
					{
						printf("");
					}
					dx=mod*y;
					dx=dx/d+(dx%d!=0);

					//if(y==0) while(1);
					tp=x*y;
					tp=(tp%tp2+tp2)%tp2;
					if(tp<dx)
					{
						tp3=dx-tp;
						tp3=tp3/tp2+(tp3%tp2!=0);
						tp=tp+=tp3*tp2;
					}
					if(ans>tp) ans=tp;
				}
			}
			if(ans==0x7fffffffffffffff) ans=-1;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}