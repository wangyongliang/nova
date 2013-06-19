#include<stdio.h>
int main()
{
	char s[1000]={0};
	int i,j,k;
	scanf("%s",s);
	for(i=2;s[i];)
	{
		if(s[i]>='A'&&s[i]<='z')
		{
			for(;s[i]>='A'&&s[i]<='Z';i++) printf("%c",s[i]);
			for(;s[i]>='0'&&s[i]<='9';i++) printf("%c",s[i]);
			if(s[i]=='=') printf("="),i++;
			for(;s[i]>='0'&&s[i]<='9';i++) printf("%c",s[i]);
			printf("\n");
		}
		else
		{
			printf("%c",s[i++]);
			if(s[i]>='A'&&s[i]<='Z') printf("%c",s[i++]);
			if(s[i]>='0'&&s[i]<='9') printf("%c",s[i++]);
			if(s[i]=='=') printf("%c",s[i++]);
			for(;s[i]>='0'&&s[i]<='9';i++) printf("%c",s[i]);
			printf("\n");
		}
	}
	return 0;
}