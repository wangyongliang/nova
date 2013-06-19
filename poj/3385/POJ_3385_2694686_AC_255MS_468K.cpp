#include<stdio.h>
int a[100010];
int main()
{
	int n,d,j,i;
	int ans;
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		ans=0;
		for(i=0;i<n;i++) a[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a[j]++;
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>d)
			{
				if((a[i]-d)%(d-1)) ans+=(a[i]-d)/(d-1)+1;
				else ans+=(a[i]-d)/(d-1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}