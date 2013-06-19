#include<stdio.h>
#include<algorithm>
using namespace std;
char s[200][10]={0};
int f(char s1[],char s2[])
{
	int i,j,ii,jj;
	int ans=0;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			for(ii=0;ii<5;ii++) if(s1[i]==s2[ii]) break;
			for(jj=0;jj<5;jj++) if(s1[j]==s2[jj]) break;
			ans+=(ii>jj);
		}
	}
	return ans;
}
char per[200][10]={0};
int main()
{
	char str[]={"ABCDE"};
	int cnt[200];
	int i,j=0,n;
	do
	{
		for(i=0;i<5;i++) per[j][i]=str[i];
		j++;
	}
	while(next_permutation(str,str+5));
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%s",s[i]);
		for(i=0;i<120;i++)
		{
			cnt[i]=0;
			for(j=0;j<n;j++)
			{
				cnt[i]+=f(per[i],s[j]);
			}
		}
		for(i=j=0;i<120;i++)
		{
			if(cnt[i]<cnt[j]) j=i;
		}
		printf("%s is the median ranking with value %d.\n",per[j],cnt[j]);
	}
	return 0;
}