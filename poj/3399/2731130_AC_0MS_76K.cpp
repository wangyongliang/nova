#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;
int main()
{
	int a[110];
	int n,k;
	bool flag[110];
	int i,j,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		flag[i]=0;
	}
	sort(a,a+n);
	i=0;
	j=n-1;
	if(k&1)
	{
		if(a[n-1]>0) {flag[n-1]=1;k--,j=n-2;}
		else
		{
			for(;k;j--,k--) flag[j]=1;
		}
	}
	while(k)
	{
		if(a[i]*a[i+1]>=a[j]*a[j-1])
		{
			flag[i]=flag[i+1]=1;
			i=i+2;
		}
		else
		{
			flag[j]=flag[j-1]=1;
			j-=2;
		}
		k-=2;
	}	
	for(i=n-1;!flag[i];i--) ;
	printf("%d",a[i]);
	for(i--;i>=0;i--)
	{
		if(flag[i]) printf(" %d",a[i]);
	}
	printf("\n");
	return 0;
}