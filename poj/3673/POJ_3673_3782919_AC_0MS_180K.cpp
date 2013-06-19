#include<stdio.h>
int a[20],b[20];
int ans;
int main()
{
	int n,m;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<20;i++) a[i]=b[i]=0;
		for(i=0;n;i++)
		{
			a[i]=n%10;
			n/=10;
		}
		n=m;
		for(i=0;n;i++)
		{
			b[i]=n%10;
			n/=10;
		}
		ans=0;
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++) ans+=a[i]*b[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
