#include<stdio.h>
#include<algorithm>
#include<math.h>
#define max 50010
#define size 500100
using namespace std;
struct node
{
	int x;
	int y;
	int flag;
}q[max],p[max],a[max];
int ans[size];
int n;
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool cp(const node &x,const node &y)
{
	return x.flag<y.flag;
}
int lowbit(int i)
{
	return i&(-i);
}
int sum(int i)
{
	int an=0;
	while(i>0)
	{
		an+=ans[i];
		i-=lowbit(i);
	}
	return an;
}
void jia(int i)
{
	while(i<size)
	{
		ans[i]++;
		i+=lowbit(i);
	}
}
int main()
{
	int i,j;
	int t;
	int m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&q[i].x,&q[i].y);
			q[i].x++;
			q[i].y++;
		}
		sort(q,q+n,cmp);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].x++;
			p[i].y++;
			p[i].flag=i;
		}
		sort(p,p+m,cmp);
		for(i=0;i<size;i++) ans[i]=0;
		for(j=i=0;i<n;i++)
		{
			while(j<m&&q[i].x>p[j].x)
			{
				a[j].x=sum(p[j].y);
				a[j].flag=p[j].flag;
				j++;
			}
			jia(q[i].y);
		}
		for(;j<m;j++)
		{
			a[j].x=sum(p[j].y);
			a[j].flag=p[j].flag;
		}
		for(i=0;i<size;i++) ans[i]=0;
		for(j=m-1,i=n-1;i>=0;i--)
		{
			while(j>=0&&q[i].x<p[j].x)
			{
				a[j].y=sum(p[j].y);
				a[j].y=n-i-1-a[j].y;
				a[j].flag=p[j].flag;
				j--;
			}
			jia(q[i].y);
		}
		for(;j>=0;j--)
		{
			a[j].y=n-sum(p[j].y);
			a[j].flag=p[j].flag;
		}
		sort(a,a+m,cp);
		for(i=0;i<m;i++)
		{
			printf("%d\n",abs(n-2*(a[i].x+a[i].y)));
		}
		printf("\n");
	}
	return 0;
}

