#include<stdio.h>
int a[1010];
int main()
{
	int n,m,i,j,ans;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if(ans==0) printf("0\n");
		else
		{
			j=ans;
			i=0;
			while(j)
			{
				j>>=1;
				i++;
			}
			j=i-1;
			ans=0;
			for(i=0;i<n;i++)
			{
				if(a[i]&(1<<j)) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}