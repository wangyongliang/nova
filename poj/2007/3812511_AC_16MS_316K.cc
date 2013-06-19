#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[100];
int cross(const node x,const node y)
{
	int dx1,dy1,dx2,dy2;
	dx1=x.x-a[0].x;
	dy1=x.y-a[0].y;
	dx2=y.x-a[0].x;
	dy2=y.y-a[0].y;
	return dx1*dy2-dx2*dy1;
}
bool cmp(const node &x,const node &y)
{
	return cross(x,y)>0;
}
int main()
{
	int n=0;
	while(scanf("%d%d",&a[n].x,&a[n].y)!=EOF) n++;
	sort(a+1,a+n,cmp);
	int i;
	for(i=0;i<n;i++) printf("(%d,%d)\n",a[i].x,a[i].y);
	return 0;
}