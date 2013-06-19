#include<stdio.h>
#include<algorithm>
#define inf 1000000
using namespace std;
int a[20100][2]={0};
struct node
{
	int x,y;
}b[2100];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int find(int x,int y)
{
	if(x<0) return 0;
	if(!a[x][0]) return 0;
	int min=a[x][0],max=a[x][1],mid;
	while(min<max)
	{
		mid=(min+max)/2;
		if(b[mid].y>y) max=mid;
		else if(b[mid].y==y) return 1;
		else min=mid+1;
	}
	if(b[min].y==y) return 1;
	else return 0;
}
int main()
{
	int n,i,j;
	int dx,dy;
	int x1,y1,x2,y2;
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i].x+=10000;
	}
	sort(b+1,b+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(!a[b[i].x][0]) a[b[i].x][0]=i;
		a[b[i].x][1]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			dx=b[j].x-b[i].x;
			dy=b[j].y-b[i].y;
			x1=b[i].x+dy;
			y1=b[i].y-dx;
			x2=x1+dx;
			y2=y1+dy;
			if(find(x1,y1)&&find(x2,y2)) ans++;
			x1=b[i].x-dy;
			y1=b[i].y+dx;
			x2=x1+dx;
			y2=y1+dy;  
			if(find(x1,y1)&&find(x2,y2)) ans++;
		}
	}
	printf("%d\n",ans/4);
	return 0;
}