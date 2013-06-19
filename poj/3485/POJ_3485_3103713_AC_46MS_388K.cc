#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxn 1000000
struct node
{
	double x,y;
}a[maxn];
bool cmp(const node &x,const node &y)
{
	return x.x<y.x; 
}
int main()
{
	int n,i,j,l;
	double d, xx,x,y;
	while(scanf("%d%lf%d",&l,&d,&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			xx=sqrt(d*d-y*y);
			a[i].x=x-xx;
			a[i].y=x+xx;
		}
		sort(a,a+n,cmp);
		x=a[0].x;
		y=a[0].y;
		j=1;
		for(i=1;i<n;i++)
		{
			if(a[i].x<=y)
			{
				x=x<a[i].x?a[i].x:x;
				y=y<a[i].y?y:a[i].y;
			}
			else
			{
				j++;
				x=a[i].x;
				y=a[i].y;
			}
		}
		printf("%d\n",j);
	}
	return 0;
}
