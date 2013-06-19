#include<stdio.h>
int main()
{
	int ans;
	int i,j,k,a,b,c;
	int ans1,ans2,ans3;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ans=2*n+2+2*n;
		ans1=n;
		ans2=ans3=1;
		for(i=1;i*i*i<=n;i++)
		{
			if(n%i==0)
			{
				a=i;
				for(j=i;j*i*j<=n;j++)
				{
					b=i*j;
					if(n%b==0)
					{
						c=n/b;
						b=j;
						k=2*a*b+2*a*c+2*b*c;
						if(k<ans)
						{
							ans1=a;
							ans2=b;
							ans3=c;
							ans=k;
						}
					}
				}
			}
		}
		printf("%d %d %d\n",ans1,ans2,ans3);
	}
	return 0;
}