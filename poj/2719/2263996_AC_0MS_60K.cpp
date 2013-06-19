#include<stdio.h>
int main()
{
	int n,k,i;
	char s[10];
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='0')break;
		for(i=0,n=0;s[i];i++)
		{
			n=n*9+(s[i]>'4'?s[i]-'0'-1:s[i]-'0');
		}
		printf("%s: %d\n",s,n);
	}
	return 0;
}