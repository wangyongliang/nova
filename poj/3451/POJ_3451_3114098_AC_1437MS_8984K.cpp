#include<stdio.h>
#define maxn 1001000
int b1[maxn],b2[maxn];
bool flag[maxn];
int main()
{
	int n,i,j,m,x,ans,max;
	double f;
	while(scanf("%lf",&f))
	{
		if(f<0) break;
		f=f*100+0.5;
		n=(int)f;
		for(i=0;i<maxn;i++) flag[i]=0,b1[i]=-1;
		flag[0]=1;
		b1[0]=0;
		max=1;
		while(scanf("%lf",&f))
		{
			if(f<0) break;
			f=f*100+0.5;
			x=(int)f;
			scanf("%dx",&m);
			for(i=max;i>=0;i--)
			{
				if(flag[i])
				{
					for(j=0;j<=m;j++)
					{
						if(i+x*j>=maxn) continue;
						if(max<i+x*j) max=i+x*j;
						if(flag[i+x*j])
						{
							if(b1[i+x*j]>b1[i]+j) b1[i+x*j]=b1[i]+j;
						}
						else flag[i+x*j]=1,b1[i+x*j]=b1[i]+j;
					}
				}
			}
		}
		for(i=0;i<maxn;i++) flag[i]=0,b2[i]=-1;
		flag[0]=1;
		b2[0]=0;
		max=1;
		while(scanf("%lf",&f))
		{
			if(f<0) break;
			f=f*100+0.5;
			x=(int)f;
			scanf("%dx",&m);
			for(i=max;i>=0;i--)
			{
				if(flag[i])
				{
					for(j=0;j<=m;j++)
					{
						if(i+x*j>=maxn) continue;
						if(i+x*j>max) max=i+x*j;
						if(flag[i+x*j])
						{
							if(b2[i+x*j]>b2[i]+j) b2[i+x*j]=b2[i]+j;
						}
						else flag[i+x*j]=1,b2[i+x*j]=b2[i]+j;
					}
				}
			}
		}
		ans=0x7fffffff;
		for(i=n;i<=max;i++)
		{
			if(b1[i]!=-1&&b2[i-n]!=-1) ans=ans>b1[i]+b2[i-n]?b1[i]+b2[i-n]:ans;
		}
		if(ans==0x7fffffff) printf("The payment is impossible.\n");
		else printf("%d tenders must be exchanged.\n",ans);
	}
	return 0;
}