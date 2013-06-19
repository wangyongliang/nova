#include<stdio.h>
int gcd(int n,int m)
{
	int r=n%m;
	while(r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
int main()
{
	int n,x,k,i,m;
	int ans;
	while(scanf("%d%d%d",&n,&x,&k)!=EOF)
	{
		if(n==0) printf("No\n");
		else
		{
			scanf("%d",&ans);
			for(i=1;i<n;i++)
			{
				scanf("%d",&m);
				while(m%k==0) m/=k;
				ans=gcd(ans,m);
			}
			if(k%ans==0||x%ans==0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

