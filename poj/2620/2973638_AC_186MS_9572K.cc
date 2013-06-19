#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[200000+100];
int q[2000000+100];
bool cmp(const node &n,const node &m)
{
	if(n.x==m.x) return n.y>m.y;
	return n.x<m.x;
}
int main()
{
	int m;
	int i,j;
	int qs;
	while(scanf("%d",&m)!=EOF){
	for(i=0;;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x==0&&a[i].y==0) break;
	//	if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		if(a[i].y<=0) i--;
	}
	sort(a,a+i,cmp);
	j=i;
	if(a[0].x>0)
	{
		printf("No solution\n");
		continue;
	}
	for(i=qs=0;a[i].x<=0;i++)
	{
		if(a[i].y>a[qs].y) qs=i;
	}
	q[0]=qs;
	qs=0;
	for(;i<j&&a[q[qs]].y<m;i++)
	{
		if(a[i].x>a[q[qs]].y) break;
		if(a[i].y<=a[q[qs]].y) continue;
		else
		{
			while(qs>0&&a[q[qs-1]].y>=a[i].x) qs--;
			qs++;
			q[qs]=i;
		}
	}
	if(a[q[qs]].y<m) printf("No solution\n");
	else
	{
		printf("%d\n",qs+1);
		for(i=0;i<=qs;i++) printf("%d %d\n",a[q[i]].x,a[q[i]].y);
	}}
	return 0;
}