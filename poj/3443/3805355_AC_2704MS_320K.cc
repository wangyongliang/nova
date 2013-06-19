#include<stdio.h>
#include<algorithm>
using namespace std;
bool flag[400];
int flg[20];
int a[20];
int tp[3][20],cnt[3];
int ans,n;
int m;
int ck(int t,int deep,int len)
{
	if(flag[m]==1) printf("bad\n");
	int i;
	if(t==2&&deep==cnt[2]-1) return 1;
	else
	{
		if(deep==cnt[t]-1) return ck(t+1,0,0);
		else
		{
			for(i=deep;i<cnt[t];i++)
			{
				flag[m]=0;
				if(flag[tp[t][i]+len]==0)
				{
					if(i!=deep&&tp[t][deep]==tp[t][i]) continue;
					swap(tp[t][deep],tp[t][i]);
					flag[tp[t][i]+len]=1;
					flag[m]=0;
					if(ck(t,deep+1,len+tp[t][i])) return 1;
					swap(tp[t][deep],tp[t][i]);
					flag[tp[t][i]+len]=0;
				}
			}
			return 0;
		}
	}
}
void dfs(int t,int len,int k)
{
	int i;
	if(t==2)
	{
		for(i=0;i<n;i++)
		{
			if(flg[i]==-1) flg[i]=2;
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		for(i=0;i<n;i++)
		{
			if(flg[i]>=0)
			{
				tp[flg[i]][cnt[flg[i]]++]=a[i];
			}
		}
		if(cnt[0]==1||cnt[1]==1||cnt[2]==1) return ;
		for(i=0;i<400;i++) flag[i]=0;
		if(ck(0,0,0)) ans=ans<m?m:ans;	
		for(i=0;i<n;i++)
		{
			if(flg[i]==2) flg[i]=-1;
		}
	}
	else
	{
		if(len==0) dfs(t+1,m,0);
		else
		{
			for(i=k;i<n;i++)
			{
				if(flg[i]==-1)
				{
					if(a[i]>len) return ;
					flg[i]=t;
					dfs(t,len-a[i],i);
					flg[i]=-1;
				}
			}
		}
	}
}

int main()
{
	int i,j,k,ct;
	int t=1;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		ans=0;
		for(i=0;i<(1<<n);i++)
		{
			k=i;
		//	printf("%d\n",i);
			for(j=0;j<n;j++,k/=2) flg[j]=k%2;
			ct=0;
			for(j=k=0;j<n;j++) 
			{
				ct+=flg[j];
				if(flg[j]==1) flg[j]=-1,k+=a[j];
				else flg[j]=-2;
			}
			if(k%3==0&&ct>=6) 
			{
				m=k/3;
				dfs(0,m,0);
			}
		}
		printf("Case %d: %d\n",t++,ans);
	}
	return 0;
}