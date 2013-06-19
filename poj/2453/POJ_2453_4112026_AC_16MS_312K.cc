#include<stdio.h>
int main()
{
	int n;
	int a[100];
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<100;i++) a[i]=0;
		for(i=0;n;i++,n/=2) a[i]=n%2;
		int k=0;
		for(i=0;;i++)
		{
			if(a[i])
			{
				k++;
				if(a[i+1]==0)
				{
					a[i]=0;
					a[i+1]=1;
					break;
				}
			}
			a[i]=0;
		}
		k--;
		for(i=0;k;i++,k--) a[i]=1;
		int ans=0;
		for(i=99;i>=0;i--) ans=ans*2+a[i];
		printf("%d\n",ans);
	}
	return 0;
}