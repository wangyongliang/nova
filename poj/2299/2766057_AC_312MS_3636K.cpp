#include<stdio.h>
#define size 501000 
int a[size];
int temp[size];
__int64 ans;
void megresort(int x,int y)
{
	int mid;
	
	if(x==y) return ;
	mid=(x+y)/2;
	megresort(x,mid);
	megresort(mid+1,y);
	int k=y,i=mid,j=y;
	while(i>=x&&j>=mid+1)
	{			
		if(a[i]>a[j])  temp[k--]=a[j--];
		else
		{
			temp[k--]=a[i--];
			ans+=y-j;
		}
	}
	while(i>=x)
	{
		temp[k--]=a[i--];
		ans+=y-mid;
	}
	while(j>=mid+1) temp[k--]=a[j--];
	for(i=x;i<=y;i++) a[i]=temp[i];
}

int main()
{
	int n;
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		ans=0;
		megresort(0,n-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
