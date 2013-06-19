#include<stdio.h>
#define maxn 1001000
char s[maxn];
int div()
{
	int i,n;
	n=s[0]-'0';
	for(i=1;s[i];i++)
	
	{
		n=n*10+s[i]-'0';
		n%=11;
	}
	return n;
}
int main()
{
	int i,j,k,n;
	int t=1;
	while(scanf("%s",s+1)!=EOF)
	{
		if(s[1]=='0'&&s[2]=='\0') break;
		if(s[1]=='0') i='2';
		else i='1';
		for(;i<='9'+1;i++)
		{
			s[0]=i;
			if(!div()) break;
		}
		printf("%d. ",t++);
		if(i>'9'+1) printf("IMPOSSIBLE\n");
		else
		{
			n=s[0]-'0';
			for(i=1;s[i];i++)
			{
				n=n*10+s[i]-'0';
				printf("%d",n/11);
				n%=11;
			}
			printf("\n");
		//	printf("%d\n",n/11);
		}
	}
	return 0;
}