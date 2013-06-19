#include<stdio.h>
#include<algorithm>
#define size 501000 
using namespace std;
int a[size];
int b[size];
__int64 ans;
void f(int x,int y)
{
	int mid;
	int i,j,k;
	if(y<=x+1)
	{
		if(a[x]>a[y]) 
		{
			ans++;
		}
		else swap(a[x],a[y]);
	}
	else
	{
		mid=(x+y)/2;
		f(x,mid);
		f(mid+1,y);
		k=y;
		i=mid;
		j=y;
		while(i>=x&&j>=mid+1)
		{			
			if(a[i]>a[j])  b[k--]=a[j--];
			else
			{
				b[k--]=a[i--];
				ans+=y-j;
			}
		}
		while(i>=x)
		{
			b[k--]=a[i--];
			ans+=y-mid;
		}
		while(j>=mid+1) b[k--]=a[j--];
		for(i=x;i<=y;i++) a[i]=b[i];
	}
}
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		ans=0;
		f(0,n-1);
		printf("%I64d\n",ans);
	}
	return 0;
}