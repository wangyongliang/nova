#include<stdio.h>
int ans[200];
void mut(int n)
{
	int i;
	for(i=1;i<200;i++)
	{
		ans[i]*=n;
	}
	for(i=1;i<200;i++)
	{
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
}
void div(int n)
{
	int i,mod,d=0;
	for(i=199;i>=1;i--)
	{
		d=d*10+ans[i];
		ans[i]=d/n;
		d%=n;
	}
}
int main()
{
	int i,j,n;
	while(scanf("%d",&n)&&n!=-1)
	{
		if(n==1) printf("1\n");
		else if(n==2) printf("2\n");
		else
		{
			for(i=0;i<200;i++) ans[i]=0;
			ans[0]=1;
			ans[1]=5;
			for(i=4;i<=n;i++)
			{
				mut(4*i-2);
				div(i+1);
			}
			for(i=199;ans[i]==0;i--);
			for(;i>=1;i--) printf("%d",ans[i]);
			printf("\n");
		}
	}
	return 0;
}