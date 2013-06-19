#include<stdio.h>
#include<math.h>
char s[100],n;
bool check(double x)
{
	int i,j;
	for(i=2,x*=10;s[i];i++,x*=10)
	{
		j=(int)x;
		j%=10;
		if(j!=s[i]-'0'+0) return 0;
	}
	return 1;
}
int main()
{
	int n,i,j;
	__int64 ans;
	double x,dx,eps,y;
	while(scanf("%d",&n)!=EOF)
	{
		s[0]='0';
		s[1]='.';
		scanf("%s",s+2);
		dx=atof(s);
		eps=pow(0.1,n+1);
		for(i=0;i<=1<<17;i++)
		{
			x=i+dx;
		//	if(i=11111)
			x*=x;
			if(x>(__int64)x+0.5) ans=(__int64)(x+1);
			else ans=(__int64) x;
			y=sqrt(ans);
			y=y-(int)y;
			if(check(y)) break;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
