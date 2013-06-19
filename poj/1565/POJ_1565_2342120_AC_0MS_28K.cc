#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i;
	long n,m;
	while(1)
	{
		gets(s);
		if(strlen(s)==1&&s[0]=='0')break;
		else
		{
			m=2;
			n=0;
			for(i=strlen(s)-1;i>=0;m*=2,i--)
				n+=(m-1)*(s[i]-'0');
		}
		printf("%ld\n",n);
	}
	return 0;
}