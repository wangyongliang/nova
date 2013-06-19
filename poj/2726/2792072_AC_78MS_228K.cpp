
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node
{
	int x,y;
}a[10010];
bool cmp(const node &t1,const node &t2)
{
	if(t1.x==t2.x) return t1.y<t2.y;
	return t1.x<t2.x;
}
int main()
{
	int n,i,j;
	int min,ans;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		min=9999999;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(min>a[i].y) ans++,min=a[i].y;
		}
		printf("%d\n",ans);
	}
	return 0;
}