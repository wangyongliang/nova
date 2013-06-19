#include<stdio.h>
__int64 ans,x,y;
__int64 abs(__int64 x)
{
	if(x>0) return x;
	else return -x;
}
void f(__int64 xx,__int64 yy)
{
	if(ans==0||ans>xx*yy)
	{
		ans=xx*yy;
		x=xx;
		y=yy;
	}
	else if(ans==xx*yy)
	{
		if(abs(x-y)>abs(xx-yy))
		{
			x=xx;
			y=yy;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	__int64 n,i,j,xx,yy;
	while(t--)
	{
		scanf("%I64d",&n);
		ans=0;
		if(n%5) n=n/5+1;
		else n=n/5;
		for(i=1;i*i<=n;i++)
		{
			xx=i;
			yy=n/i;
			if(n%i) yy++;
			f(xx*40+(xx+1)*4,yy*8+(yy+1)*2);
			yy=i;
			xx=n/i;
			if(n%i) xx++;
			f(xx*40+(xx+1)*4,yy*8+(yy+1)*2);
		}
		if(x>y)		printf("%I64d X %I64d = %I64d\n",x,y,ans);
		else 	printf("%I64d X %I64d = %I64d\n",y,x,ans);
	}
	return 0;
}
