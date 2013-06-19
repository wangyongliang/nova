#include<stdio.h>
void main()
{
	int a[26]={0},i,j=4,max;
	char s[80];
	while(j--)
	{
		gets(s);
		for(i=0;s[i];i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				a[s[i]-'A']++;
		}
	}
	for(max=a[0],i=0;i<26;i++) max=max>a[i]?max:a[i];
	for(;max>0;max--)
	{
		if(a[0]==max) printf("*"),a[0]--;
		else printf(" ");
		for(i=1;i<26;i++)
		{
			if(a[i]==max) printf(" *"),a[i]--;
			else printf("  ");
		}
		printf("\n");
	}
	printf("A");
	for(i='B';i<='Z';i++)
		printf(" %c",i);
	printf("\n");
}