#include<stdio.h>
int main()
{
	char s[30];
	int i;
	char ss[10000];
	while(scanf("%s",s)!=EOF)
	{
		gets(ss);
		gets(ss);
		for(i=0;ss[i];i++)
		{
			if(ss[i]>='a'&&ss[i]<='z') ss[i]=s[ss[i]-'a'];
			else if(ss[i]>='A'&&ss[i]<='Z') ss[i]=s[ss[i]-'A']+'A'-'a';
		}
		printf("%s\n",ss);
	}
	return 0;
}