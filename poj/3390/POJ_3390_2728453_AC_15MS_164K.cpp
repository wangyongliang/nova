#include<stdio.h>
int a[11000];
int ans[11000];
int main()
{
	int n,m,t;
	int i,j,sum;
	int min,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=sum=0;i<n;i++)
		{
			sum+=a[i];
			if(sum+i>m) break;
			ans[i]=(m-sum-i)*(m-sum-i);
		}
		for(;i<n;i++)
		{
			min=0xfffffff;
			for(sum=0,j=i;j>=0;j--)
			{
				sum+=a[j];
				if(sum+i-j>m) break;
				temp=ans[j-1]+(m-sum-i+j)*(m-sum-i+j);
				min=min>temp?temp:min;
			}
			ans[i]=min;
		}
		printf("%d\n",ans[n-1]);
	}
	return 0;
}