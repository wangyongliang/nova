#include<stdio.h>
#include<algorithm>
using namespace std;
int b[1001000],n,a;
int f(int mid)
{
	int i,k=mid;
	int temp;
	for(i=n-1;i>=0;i--)
	{
		if((b[i]-(mid-k))/a>k) return 0;
		if(b[i]-(mid-k)>k)
		{
			k-=(b[i]-mid)/(a-1)+((b[i]-mid)%(a-1)!=0);
		}
		if(k<0) return 0;
	}
	return 1;
}
int main()
{
	int i,j;
	int min,max,mid;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		sort(b,b+n);
		scanf("%d",&a);
		max=0;
		j=0;
		for(i=0;i<n;i++) max=max<b[i]?b[i]:max;
		if(a==1) 
		{
			printf("%d\n",max);continue;
		}
		min=0;
		while(min<max)
		{
			mid=(min+max)/2;
			i=f(mid);
			if(i)max=mid;
			else min=mid+1;
		}
		printf("%d\n",min);
	}
	return 0;
}