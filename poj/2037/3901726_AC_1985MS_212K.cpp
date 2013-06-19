#include<stdio.h>
#include<time.h>
int n,a[30];
int ans[10];
int b[100],cnt[100];
int tp[100],dp[1100],max[100];
int r,m;
int flag;
int dfs(int deep,int k)
{
	int i,j;
	long long tpp[100];
	long long tq;
	if(deep==r)
	{
		return 1;
	}
	else
	{
		for(i=k;i<=50;i++)
		{
			for(j=0;j<m;j++) tpp[j]=tp[j];
			for(j=0;j<m;j++)
			{
				if(b[j]-i>=0) tp[j]-=dp[b[j]-i];
			}
			for(j=0;j<m;j++)
			{
				if(tp[j]<0) break;
				if(deep==r-1)
				{
					if(tp[j]!=0) break;
				} 
				tq=(r-deep-1);
				tq*=max[j];
			//	tq+=tp[j];
				if(tq<0) 
					printf("bad\n");
				if(tq<tp[j]) break; 
			}
			if(j==m)
			{
				ans[deep]=i;
				if(dfs(deep+1,i)) return 1;
			}
			for(j=0;j<m;j++) tp[j]=tpp[j];
		}
		return 0;
	}
}
int main()
{
	int n,i,j,k,f;
	int big=1<<31;
	//freopen("E.dat","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<1100;i++) dp[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&f);
			for(j=0;j<f;j++) scanf("%d",&a[j]);
			if(i)
			{
				for(j=1100-1;j>=0;j--)
				{
					dp[j]=0;
					for(k=0;k<f;k++)
					{
						if(j-a[k]>=0) dp[j]+=dp[j-a[k]];
					}
				}
			}
			else
			{
				for(k=0;k<f;k++) dp[a[k]]++;
			}
		}
		scanf("%d%d",&r,&m);
		for(i=0;i<m;i++) 
		{
			scanf("%d%d",&b[i],&cnt[i]);
			tp[i]=cnt[i];
		}
		int st=clock();
		j=k=0;
		for(i=1;i<1100;i++)
		{
			k=dp[k]<dp[i]?i:k;
			if(i==b[j]) max[j++]=dp[k];
		}
		for(;j<m;j++) max[j]=dp[k];
		for(j=0;j<m;j++)
		{
			if(max[j]>cnt[j]) max[j]=cnt[j];
		}
		if(dfs(0,1))
		{
			printf("Final die face values are");
			for(i=0;i<r;i++) printf(" %d",ans[i]);
			printf("\n");
		}
		else printf("Impossible\n");
		int en=clock();
		//printf("time is %d\n",en-st);
	}
	return 0;
}