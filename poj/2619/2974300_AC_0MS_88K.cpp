#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
void f(int &x,int &y,int n,int &flag,int &deep)
{
	int xx;
	xx=(int) sqrt((double)n);
	if(xx*xx==n) xx--;
	int sum=(xx)*(xx);
	xx++;
	deep=xx;
	//x=xx;
	x=(n-sum)/2+(n-sum)%2;
	flag=(n-sum)%2;
	if(flag) y=xx-x+1;
	else y=xx-x;
}
int main()
{
	int n,m;
	int ans;
	int x1,y1,x2,y2,flag1,flag2,d1,d2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		if(n>m) swap(n,m);
		f(x1,y1,n,flag1,d1);
		f(x2,y2,m,flag2,d2);
		{
			if(x2<=x1)
			{
				ans=(x2-x1)*2;
				y1+=(x2-x1);
				ans+=(y2-y1)*2-1;
				if(flag1) ans++;
				if(flag2==0) ans++;
			}
			else 
			{
				if(y1<=y2)
				{
					ans=(x2-x1)*2+(y2-y1)*2;
					if(flag1==0) ans--;
					if(flag2==0) ans++;
				}
				else
				{
					ans=(y1-y2)*2;
					x1+=(y1-y2);
					ans+=(x2-x1)*2-1;
					if(flag1) ans++;
					if(flag2==0) ans++;
				}
			}
		}


		printf("%d\n",ans);
	}
	return 0;
}