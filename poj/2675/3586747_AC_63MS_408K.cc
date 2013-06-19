#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	double z;
}a[1000000];
bool cmp(const node &x,const node &y)
{
	return x.z>y.z;
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%lf",&a[i].x,&a[i].y,&a[i].z);
			a[i].z/=a[i].y;
		}
		sort(a,a+n,cmp);
		scanf("%d",&n);
		printf("%d\n",a[n-1].x);
	}
	return 0;
}
