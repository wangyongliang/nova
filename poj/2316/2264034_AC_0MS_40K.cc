#include<stdio.h>
int main()
{
	char s[11],c[11];
	int i;
	scanf("%s",s);
	while(scanf("%s",c)!=EOF)
	{
		for(i=0;c[i];i++)
		{
			s[i]=(s[i]+c[i]-'0'-'0')%10+'0';
		}
	}
	puts(s);
	return 0;
}