#include<stdio.h>
#define maxx 1000009
long s,n;
int a[maxx];
int check(int mid)
{
	int sum=0,i;
	int t;
	if(mid<=0) return 0;
	for(i=0;i<mid;i++) sum+=a[i];
	t=0;
	if(sum>=s) return 1;
	for(;i<n;i++)
	{
		sum=sum+a[i]-a[i-mid];
		if(sum>=s) return 1;
	}
	return 0;
}
int main()
{
	long max,min,i,sum,mid;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&s);
		min=-1;
		max=99999999;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			max=max>a[i]?a[i]:max;
			min=min<a[i]?a[i]:min;
			sum+=a[i];
		}
		if(sum<s) printf("0\n");
		else
		{
			max=s/max+1;
			min=s/min-1;
			if(max>n) max=n;
			if(min<0) min=0;
			while(min<max)
			{
				mid=(max+min)/2;
				if(check(mid))
				{
					max=mid;
				}
				else
				{
					min=mid+1;
				}
				mid=(min+max)/2;
			}
			if(check(min-1)) printf("%ld\n",min-1);
			else printf("%ld\n",min);
		}
	}
	return 0;
}