#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 1000000
struct node
{
	int x,y;
}a[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
bool cmp(const node &x,const node &y)
{
	 if(x.x==y.x) return x.y<y.y;
	 else return x.x<y.x;
}
int main()
{
	int n,t;
	int i,j,k;
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		sort(a,a+n,cmp);
		int ans=0;
		for(k=0,i=0;k<t;)
		{
			int tp=k;
			for(;i<n;i++)
			{
				if(a[i].x<=k+1) tp=max(tp,a[i].y);
				else break;
			}
			if(tp==k) break;
			else {k=tp; ans++;}
		}
		if(k<t) printf("-1\n");
		else 		printf("%d\n",ans);

	}
	return 0;
}