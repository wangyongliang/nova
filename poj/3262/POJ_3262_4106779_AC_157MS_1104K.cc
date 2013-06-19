#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[1000000];
bool cmp(const node &x,const node &y)
{
	return x.x*y.y<x.y*y.x;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		long long ans=0,t;
		t=a[0].x*2;
		for(i=1;i<n;i++)
		{
			ans+=t*a[i].y;
			t+=2*a[i].x;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}