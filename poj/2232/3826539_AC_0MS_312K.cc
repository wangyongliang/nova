#include<stdio.h>
int main()
{
	int cnt[3];
	char s[10];
	int i,j,n;
	while(scanf("%d",&n)!=EOF)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(s[0]=='C') cnt[0]++;
			else if(s[0]=='S') cnt[1]++;
			else cnt[2]++;
		}
		for(i=j=0;i<3;i++) j+=(cnt[i]!=0);
		if(j==1||j==3) printf("%d\n",cnt[0]+cnt[1]+cnt[2]);
		else 
		{
			if(cnt[0]&&cnt[1]) printf("%d\n",cnt[0]);
			else if(cnt[1]&&cnt[2]) printf("%d\n",cnt[1]);
			else printf("%d\n",cnt[2]);
		}
	}
	return 0;
}