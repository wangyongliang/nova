//pku 1468 1470 的其他方法
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node 
{
	int x,y;
}a[10009];
bool cmp(const node &x,const node &y)
{
	if(x.y==y.y) return x.x<y.x;
	else return x.y<y.y;
}
int Mu(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[j].x;
	dy1=a[i].y-a[j].y;
	return dx*dy1-dy*dx1;
}
int Mu1(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[k].x;
	dy1=a[i].y-a[k].y;
	return dx*dy1-dy*dx1;
}
int main()
{
	int i,j,n;
	int q[10010],qq;
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		if(n==1) printf("0\n");
		else
		{
			sort(a,a+n,cmp);
			q[0]=0;
			q[1]=1;
			qq=1;
			for(i=2;i<n;i++)
			{
				while(Mu(i,q[qq],q[qq-1])<0) qq--;
				q[++qq]=i;
			}
			for(i=n-1;i>=0;i--)
			{
				while(Mu(i,q[qq],q[qq-1])<0)qq--;
				q[++qq]=i;
			}
			ans=0;
			a[n].x=a[n].y=0;
			for(i=0;i<qq;i++)
			{
				ans+=Mu1(q[i],q[i+1],n);
			}
			ans=ans<0?-ans:ans;
			printf("%d\n",ans/100);
		}
	}
	return 0;
}
