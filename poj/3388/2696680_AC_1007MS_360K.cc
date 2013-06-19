#include<stdio.h>
#include <algorithm>

using namespace std;

int a[50009];
int  n,k;

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int f(int mid)
{
	int i,j=0;
	int ans=0;
	for(i=0;i<k;i++)
	{
		ans+=a[i]/mid;
		if(ans>=n) return 1;
	}
	return 0;
	
}

int main()
{
	int min,mid,max,i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++) scanf("%d",&a[i]);
	min=1;
	max=n;
	int ans;
	while(min<=max)
	{
		mid=(min+max) / 2;
		if(f(mid))
		{
			min=mid+1;
			ans = mid;
		}
		else
		{
			max=mid-1;
		}
	}
	printf("%d\n",ans);
	int x = 0;
	//sort(a,a+n,cmp);
	if (ans == 1)
	{
		for (i=0,j=0; i<k&&j<n; i++)
		{
			while (j<n && a[i]>0)
			{
				if (x)
					printf("\n");
				x = 1;
				printf("%d",i+1);
				j++;
				a[i]--;
			}
		}
		return 0;
	}
	for(j=0,i=0;i<k&&j<n;i++)
	{
		while (j<n && a[i]>=ans)
		{
			j++;
			a[i] -= ans;
			printf("%d\n",i+1);
		}
	}
	return 0;
}