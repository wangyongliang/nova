#include<stdio.h> 
int a[20];
char s[30][30],ss[30][30];
int n1,m1,n2,m2;
int dfs(int deep,int p)
{
	int i,j,k;
	if(deep==m1)
	{
		for(k=i=0;i<n2&&k<n1;i++)
		{
			for(j=0;j<m1;j++)
			{
				if(s[k][j]!=ss[i][a[j]]) break;
			}
			if(j==m1) k++;
		}
		if(k==n1) return 1;
		else return 0;
	}
	else
	{
		for(i=p;i<m2;i++)
		{
			a[deep]=i;
			if(dfs(deep+1,i+1)==1) return 1;
		}
		return 0;
	}
}
int main()
{
	int i;
	while(scanf("%d%d",&n1,&m1)!=EOF)
	{
		for(i=0;i<n1;i++) scanf("%s",s[i]);
		scanf("%d%d",&n2,&m2);
		for(i=0;i<n2;i++) scanf("%s",ss[i]);
		if(dfs(0,0)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}