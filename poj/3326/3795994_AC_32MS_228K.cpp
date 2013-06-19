#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int t,n,m,s;
}a[11000];
int b[10010];

int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
struct seg
{
	int x,y;
}c[11000];
bool cmp(const seg &x,const seg &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
int main()
{
	int n,m,r,q;
	int i,j;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		scanf("%d",&r);
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d%d",&a[i].t,&a[i].n,&a[i].m,&a[i].s);
		}
		scanf("%d",&q);
		int k1,k2,k;
		while(q--)
		{
			scanf("%d%d%d",&k1,&k2,&j);
			for(i=1;i<=n;i++) b[i]=k2;
			int ans=0;
			k=0;
			for(i=0;i<r&&a[i].t<=k2;i++)
			{
				if(a[i].m!=j) continue;
				if(a[i].s==0)
				{
					if(a[i].t>k1)
					{
						c[k].y=a[i].t;
						if(b[a[i].n]<k1) c[k].x=k1;
						else c[k].x=b[a[i].n];
						k++;
					}
					b[a[i].n]=k2;
				}
				else b[a[i].n]=a[i].t;
			}
			j=k2;
			for(i=1;i<=n;i++) 
			{
				if(b[i]<k2)
				{
					if(b[i]>k1)	c[k].x=b[i];
					else c[k].x=k1;
					c[k].y=k2;
					k++;
				}
			}
			sort(c,c+k,cmp);
			ans=0;
			int pre=-1;
			for(i=0;i<k;i++)
			{
				if(c[i].y>pre)
				{
					if(c[i].x>pre) pre=c[i].x;
					ans+=c[i].y-pre;
					pre=c[i].y;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}