#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int n,int m)
{
	int r=n%m;
	while(r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
struct node
{
	int x,y;
}a[1010];
bool cmp(const node x,const node y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
node b[1010];
bool operator ==(const node x,const node y)
{
	return x.x==y.x&&y.y==y.y;
}
int ABS(int x)
{
	if(x>0) return x;
	else return -x;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)&&n)
	{

		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
				if(n==1) 
		{
			printf("1\n");
			continue;
		}
	//	sort(a,a+n,cmp);
		int ans;
		ans=2;
		int cnt;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					b[j].x=b[j].y=0;
					continue;
				}
				b[j].x=a[i].x-a[j].x;
				b[j].y=a[i].y-a[j].y;
						
				if(b[j].x==0)
				{
					b[j].y=1;
					continue;
				}
				if(b[j].y==0) 
				{
					b[j].x=1;
					continue;
				}
				int r=gcd(ABS(b[j].x),ABS(b[j].y));
				b[j].x/=r;
				b[j].y/=r;
				if(b[j].x<0) 
				{
					b[j].x=-b[j].x;
					b[j].y=-b[j].y;
				}
		
			}
			sort(b,b+n,cmp);
			cnt=0;
			
			for(j=1;j<n;j++)
			{
				if(b[j].x==b[j-1].x&&b[j].y==b[j-1].y) cnt++;
				else
				{
					if(ans<cnt+2) ans=cnt+2;
					cnt=0;
				}
			}
			if(ans<cnt+2) ans=cnt+2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
