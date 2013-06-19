#include<stdio.h>
#include<string.h>
int main()
{
	char s[110],ss[110];
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s,ss);
		for(j=i=0;s[i];i++)
		{
			if(s[i]==ss[j]) j++;
		}
		if(j<strlen(ss))
		{
			j=0;
			for(;i>=0;i--)
			{
				if(s[i]==ss[j]&&j>=0) j++;
			}
			if(j>=strlen(ss)) printf("YES\n");
			else printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}