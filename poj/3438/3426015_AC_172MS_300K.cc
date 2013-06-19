#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
	int t;
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		int cnt=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]==s[i-1]) cnt++;
			else 
			{
				printf("%d%c",cnt,s[i-1]);
				cnt=1;
			}
		}
		printf("\n");
	}
	return 0;
}