#include<stdio.h>
int n,m,r,c;
char s[110][110];
int f(int i,int j)
{
	int k,l;
	for(k=0;k<r;k++)
	{
		if(k+i>=n) return -1;
		for(l=0;l<c;l++)
		{
			if(j+l>=m) return -1;
			if(s[k+i][l+j]=='1')s[k+i][l+j]='0';
			else s[k+i][l+j]='1';
		}
	}
	return 1;
}
int main()
{
	int i,j,flag;
	int ans;
	while(scanf("%d%d%d%d",&n,&m,&r,&c)&&(n+m+r+c))
	{
		ans=0;
		for(i=0;i<n;i++) scanf("%s",s[i]);
		while(1)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(s[i][j]=='1') goto line;
				}
			}
line:
			if(i==n) 
			{
				flag=1;
				break;
			}
			flag=f(i,j);		
			if(flag==1) ans++;
			else break;
		}
		if(flag==1) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}