#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	double ans[100];
	int a[100],aa,b[100],bb;
	while(scanf("%d",&aa)&&aa)
	{
		scanf("%d",&bb);
		for(int i=0;i<aa;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<bb;i++)
		{
			scanf("%d",&b[i]);
		}
		int k=0;
		for(i=0;i<aa;i++)
		{
			for(int j=0;j<bb;j++)
			{
				ans[k++]=a[i]*1.0/b[j];
			}
		}
		double min=0;
		sort(ans,ans+k);
		for(i=0;i<k-1;i++)
		{
			if(ans[i+1]/ans[i]>min) min=ans[i+1]/ans[i];
		}
		printf("%.2lf\n",min);
	}
	return 0;
}