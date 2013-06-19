/*#include<stdio.h>
#include<algorithm>
#include<math.h>
#define size 1009
#define pi 3.141592653
using namespace std;
struct point
{
	int x;
	int y;
}a[size];
int n;
bool flag[size];
int  distance( const point p1,const point  p2 ) 
{
    return sqrt( ( p1.x-p2.x )*( p1.x-p2.x )+( p1.y-p2.y )*( p1.y-p2.y ) );
}
int muty(point x,point y,point z)
{
	int dx,dy,dx1,dy1;
	dx=y.x-z.x;
	dy=y.y-z.y;
	dx1=x.x-y.x;
	dy1=x.y-y.y;
	return dx*dy1-dy*dx1;
}
bool cmp(const point &x,const point &y)
{
	if(x.y==y.y)
		return x.x<y.x;
	else
		return x.y<y.y;
}
double graham()
{
	int i,tail=1,tail1=1;
	int stack[size];
	int stack1[size];
	double dis;
	stack[0]=0;
	stack[1]=1;
	//flag[0]=flag[1]=0;
	for(i=2;i<n;i++)
	{
		while(tail>=1&&muty(a[i],a[stack[tail]],a[stack[tail-1]])<=0)
		{
		//	flag[stack[tail]]=1;
			tail--;
		}
		stack[++tail]=i;
	//	flag[i]=0;
	}
	dis=0.0;
	for(i=0;i<tail;i++) 
	{
		dis=distance(a[stack[i]],a[stack[i+1]]);
	}
	dis+=distance(a[stack[tail]],a[n-1]);
	stack1[0]=n-1;
	stack[1]=n-2;
	for(i=n-3;i>=0;i--)
	{
		while(tail>=1&&muty(a[i],a[stack[tail]],a[stack[tail-1]])<=0)
		{
		//	flag[stack[tail]]=1;
			tail--;
		}
		stack[++tail]=i;
	//	flag[i]=0;
	}
	for(i=0;i<=tail;i++)
	{
		dis+=distance(a[stack[i]],a[stack[i+1]]);
	}
	return dis;
}

int main()
{
	int l,i;
	double dis;
	long ans;
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			flag[i]=1;
		}
		sort(a,a+n,cmp);
		dis=graham();
		dis+=pi*l*2;
		ans=(long)dis;
		if(dis-ans>=0.5) ans++;
		printf("%ld\n",ans);;
	}
	return 0;
}
*/


#include<stdio.h>
#include<algorithm>
#include<math.h>
#define size 1009
#define pi 3.141592653
using namespace std;
struct point
{
	int x;
	int y;
}a[size];
int n;
bool flag[size];
double distance( const point p1,const point  p2 ) 
{
    return sqrt( ( p1.x-p2.x )*( p1.x-p2.x )+( p1.y-p2.y )*( p1.y-p2.y ) );
}
int muty(point x,point y,point z)
{
	int dx,dy,dx1,dy1;
	dx=y.x-z.x;
	dy=y.y-z.y;
	dx1=x.x-y.x;
	dy1=x.y-y.y;
	return dx*dy1-dy*dx1;
}
int stack[size];
bool cmp(const point &x,const point &y)
{
	if(x.y==y.y)
		return x.x<y.x;
	return x.y<y.y;
}
double graham()
{
	int i,tail=1;
	double dis;
	stack[0]=0;
	stack[1]=1;
//	flag[0]=flag[1]=0;
	for(i=2;i<n;i++)
	{
		while(tail>=1&&muty(a[i],a[stack[tail]],a[stack[tail-1]])<0)
		{
		//	flag[stack[tail]]=1;
			tail--;
		}
		stack[++tail]=i;
//		flag[i]=0;
	}
	for(i=n-1;i>=0;i--)
	{
	//	if(flag[i])
	//	{
			while(tail>2&&muty(a[i],a[stack[tail]],a[stack[tail-1]])<0) tail--;
			stack[++tail]=i;
//		}
	}
//	while(tail>2&&muty(a[0],a[stack[tail]],a[stack[tail-1]])<0) tail--;
	//dis=0;
	//stack[tail+1]=0;
	for(i=0;i<tail;i++)
	{
		dis+=distance(a[stack[i]],a[stack[i+1]]);
	}
	return dis;
}

int main()
{
	int l,i;
	double dis;
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			flag[i]=1;
		}
		sort(a,a+n,cmp);
		dis=graham();
		dis+=pi*l*2;
		printf("%.0lf\n",dis);
	}
	return 0;
}

