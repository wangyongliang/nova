#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[1000000];
bool cmp(const node &xx,const node &yy)
{
	if(xx.x==yy.x) return xx.y<yy.y;
	return xx.x<yy.x;
}
int main()
{
	int n,i,j,max;
	while(scanf("%d",&n)&&n)
	{
		max=1000000000;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			if(max>a[i].y) max=a[i].y;
		}
		max--;
		sort(a,a+n,cmp);
		int ans=0;
//		for(i=0;i<n;i++) printf("%d %d\n",a[i].x,a[i].y);
		for(i=n-1;i>=0;i--)
		{
			if(a[i].y>max) ans++,max=a[i].y;
		}
		printf("%d\n",ans);
	}
	return 0;
}
