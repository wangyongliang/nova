//pku 1468的其他方法
#include<stdio.h>
#define maxn 999
int a[maxn];
bool flag[maxn];
int ans[maxn];
void dfs(int x,bool i)
{

		flag[x]=i;
		if(a[x]==-1) 		return;
		else dfs(a[x],i);

}
int dfs1(int x)
{
	if(flag[x]) return x;
	else
		dfs1(a[x]);
}
int main()
{
	int n,i,j,k,l;
	char c;
	while(scanf("%d",&n)!=EOF)
	{
		k=n;
		for(i=1;i<=n;i++) a[i]=-1,flag[i]=ans[i]=0;
		while(n--)
		{
			scanf("%d",&i);
			scanf(":(%d)",&j);
			while(j--)
			{
				scanf("%d",&l);
				a[l]=i;
			}
		}
		scanf("%d",&n);
		while(n--)
		{
			while(scanf("%c",&c)&&c!='(');
			scanf("%d%d",&i,&j);
			while(scanf("%c",&c)&&c!=')');

			dfs(i,1);
			ans[dfs1(j)]++;
			dfs(i,0); 
		}
		for(i=1;i<=k;i++)
		{
			if(ans[i])
			{
				printf("%d:%d\n",i,ans[i]);
			}
		}
	}
	return 0;
}