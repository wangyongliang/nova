
#include<stdio.h>

int d[][2]={1,0,-1,0,0,1,0,-1};
bool b[27];
int  n,m;
char s[26][26];
int max;
void dfs(int x,int y,int deep)
{
	int i,j,k;
	if(max<deep) max=deep;
	for(i=0;i<4;i++)
	{
		j=d[i][0]+x;
		k=d[i][1]+y;
		if(j>=0&&j<n&&k>=0&&k<m)
		{
			if(b[s[j][k]-'A']==0)
			{
				b[s[j][k]-'A']=1;
				dfs(j,k,deep+1);
				b[s[j][k]-'A']=0;
			}
		}
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)scanf("%s",s[i]);
		for(i=0;i<27;i++ ) b[i]=0;
		b[s[0][0]-'A']=1;
		max=0;
		dfs(0,0,1);
		printf("%d\n",max);
	}
	return 0;
}
