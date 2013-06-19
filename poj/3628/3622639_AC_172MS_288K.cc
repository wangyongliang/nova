#include<stdio.h>
int main()
{
	int n,a[21],b,sum;
	int ans,i,j,t;
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		ans=n;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ans+=a[i];
		}
		for(j=0;j<(1<<n);j++)
		{
			sum=0;
			t=0;
			for(i=0;i<n;i++)
			{
				if(j&(1<<i)) sum+=a[i],t++;
			}
			if(sum>=b&&sum<=ans) ans=sum;
		}
		printf("%d\n",ans-b);
	}
	return 0;
}
