#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long lld;
long long a[1000000];
int f(int min,int max,lld m)
{
	int mid;
	lld tp1,tp2;
	tp1=a[min];
	int cnt=min;
	while(min<max)
	{
		mid=(min+max+1)/2;
		tp2=a[mid];
		tp2=tp2-tp1;
		if(tp2>m) max=mid-1;
		else min=mid;
	}
	return min-cnt;
}
int main()
{
	int n;
	long long min,max,mid,ct;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%I64d",&a[i]);
		sort(a,a+n);
		min=0;
		max=a[n-1]-a[0];
		long long cnt=n;
		cnt*=(n-1);
		cnt/=2;
		cnt=cnt/2+cnt%2;
		while(min<max)
		{
			mid=(min+max+1)/2;
			ct=0;
			for(i=0;i<n;i++)
			{
				ct+=f(i,n-1,mid);
			}
			if(ct>=cnt) max=mid-1;
			else min=mid;
		}
		printf("%I64d\n",min+1);
	}
	return 0;
}