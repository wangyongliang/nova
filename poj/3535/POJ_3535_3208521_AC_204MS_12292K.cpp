#include<stdio.h>
#include<string.h>
#define maxn 1000010
int flag[maxn][30];
char s1[maxn],s2[maxn],ans[maxn];
int main()
{
	int i,j,k;
	int n,m,len;
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<30;j++) flag[i][j]=0;
		}
		while(m--)
		{
			scanf("%s",ans);
			for(i=0;i<n;i++) flag[i][ans[i]-'a']=1;
		}
		scanf("%s%s",s1,s2);
		k=0;
		ans[n]='\0';
		for(i=n-1;i>=0;i--)
		{
			a=b=c=0;
			for(j=0;j<='z'-'a';j++)
			{
				if(flag[i][j]==0)
				{
					if(j<s1[i]-'a') a++;
					if(j<s2[i]-'a') b++;
					c++;
				}
			}
		//	c++;
			a+=b+k;
			k=a/c;
			a%=c;
			a++;
			for(j=0;;j++)
			{
				if(flag[i][j]==0) a--;
				if(a==0) break;
			}
			ans[i]=j+'a';
		}
		printf("%s\n",ans);
	}
	return 0;
}