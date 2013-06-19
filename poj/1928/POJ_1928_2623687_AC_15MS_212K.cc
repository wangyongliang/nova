#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[51][51];
struct node
{
	int x,y;
	int n;
}b[3000];
bool cmp(const node &x,const node &y)
{
	return x.n>y.n;
}
int main()
{
	int i,j,t,tl,r,c,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&r,&c,&tl);
		n=0;
		for(i=1;i<=r;i++)
		{
			for(j=0;j<c;j++) 
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]) 
				{
					b[n].x=i;
					b[n].y=j;
					b[n].n=a[i][j];
					n++;
				}
			}
		}
		sort(b,b+n,cmp);
		r=0;
		c=b[0].y;
		ans=0;
		for(i=0;i<n;i++)
		{
			j=abs(b[i].x-r)+abs(b[i].y-c)+1;
			if(j+b[i].x<=tl)
			{
				tl-=j;
				r=b[i].x;
				c=b[i].y;
				ans+=b[i].n;
			}
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}