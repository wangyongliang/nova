#include<stdio.h>
#define max 10009
int c[max];
int main()
{
	int n,a,b,i,j,min;
	__int64 temp,ans,sum,tp,an;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		min=1;
		c[0]=0;
		temp=ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			ans+=c[i]*(a*(i-1)+(i-1)*(i-2)/2);
			temp+=c[i]*(i-1);
			c[i]+=c[i-1];
		}
		an=ans;
		tp=0;
		for(i=2;i<=n;i++)
		{
			temp=temp-(c[n]-c[i-1]);
			tp=tp+c[i-2];
			an=an+c[i-1]*b-temp+tp-a*(c[n]-c[i-1]);
			if(ans>an)
			{
				ans=an;
				min=i;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}