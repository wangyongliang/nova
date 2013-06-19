#include<stdio.h>
#define maxn  100000+10
bool flag[maxn][2];
int main()
{
	int n,i,m;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<=m;i++) flag[i][0]=flag[i][1]=0;
		flag[0][0]=1;
		for(i=0;i<n;i++)
		{
			int j;
			scanf("%d",&j);
			for(int k=m;k>=j;k--) 
			{
				if(flag[k-j][0]) flag[k][1]=1;
				if(flag[k-j][1]) flag[k][0]=1;
			}
		}
		int ans=0;
		for(i=1;i<=m;i++)
		{
			if(flag[i][0]^flag[i][1]==1&&flag[i][1]==1) 
			{
				ans++;
		//		printf("%d\n",i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}