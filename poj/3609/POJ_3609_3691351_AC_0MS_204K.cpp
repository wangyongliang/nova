#include<stdio.h>
#include<queue>
#include<string>
using namespace std;
queue<int> q;
int dp[1<<10];
int a[20][20];
int main()
{
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) scanf("%d",&a[i][j]);
		}
		while(q.size()) q.pop();
		for(i=0;i<(1<<8);i++) dp[i]=-1;
		j=(1<<n)-1;
		q.push(j);
		while(q.size()&&dp[1]==-1)
		{
			int tp=q.front();
			q.pop();
			for(i=0;i<m;i++)
			{
				k=0;
				for(j=0;j<n;j++)
				{
					if(tp&(1<<j)) k=k|(1<<a[j][i]);
				}
				if(k==(1<<n)-1) continue;
				if(dp[k]==-1) 
				{
					dp[k]=tp;
					q.push(k);
				}
			}
		}
		if(dp[1]==-1) printf("*\n");
		else
		{
			string ans="";
			i=1;
			while(dp[i]!=-1)
			{
				for(j=0;j<m;j++)
				{
					k=0;
					for(int l=0;l<n;l++)
					{
						if(dp[i]&(1<<l)) k=k|(1<<a[l][j]);
					}
					if(k==i)
					{
						char ch;
						if(j<10) ch='0'+j;
						else ch='a'+j-10;
						ans=ch+ans;
						break;
					}
				}
				i=dp[i];
			}
			printf("%s\n",ans.c_str());
		}
	}
	return 0;
}