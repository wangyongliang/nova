#include<stdio.h>
#include<algorithm>
using namespace std;
int cnt[200];
struct node
{
	int x,y;
}a[200];
bool flag[200];
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	int i,j,k;
	int max;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<200;i++) 
		{
			cnt[i]=0;
			flag[i]=0;
		}
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%*d%d%*d",&a[i].x,&a[i].y);
			if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
			max=max<a[i].y?a[i].y:max;
			for(j=a[i].x;j<=a[i].y;j++) cnt[j]++;
		}
		int maxx;
		int ans=0;
		for(i=0;i<=max;i++)
		{
			while(cnt[i]>k)
			{
				maxx=-1;
				for(j=0;j<n;j++)
				{
					if(a[j].x<=i&&flag[j]==0)
					{
						if(maxx==-1) maxx=j;
						else
						{
							if(a[j].y-i>a[maxx].y-i) maxx=j;
						}
					}
				}
				flag[maxx]=1;
				for(j=a[maxx].x;j<=a[maxx].y;j++) cnt[j]--;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}