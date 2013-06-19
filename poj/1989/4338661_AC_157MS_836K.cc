#include<iostream>
using namespace std;
#define maxn 1000000
int flag[maxn];
int a[maxn];
int main()
{
	int n,i,j,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<=k;i++) flag[i]=-1;
		int ans=0;
		int tp=k;
		for(i=0;i<n;i++)
		{
			if(flag[a[i]]!=ans) tp--;
			flag[a[i]]=ans;
			if(tp==0)
			{
				ans++;
				tp=k;
			}
		}
		//if(tp<k) 
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}