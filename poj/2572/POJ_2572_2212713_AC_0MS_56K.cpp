#include<stdio.h>
#include<string.h>
void main()
{
	char s[30];
	int i,j,n,m,k;
	while(1)
	{
		gets(s);
		if(!strcmp(s,"0+0=0")) 
		{
			printf("True\n");
			break;
		}
		for(m=0,j=1,i=0;s[i]!='+';i++)
		{
			m+=(s[i]-'0')*j;
			j*=10;
		}
		for(k=0,j=1,i++;s[i]!='=';i++)
		{
			k+=(s[i]-'0')*j;
			j*=10;
		}
		for(n=0,j=1,i++;s[i];i++)
		{
			n+=(s[i]-'0')*j;
			j*=10;
		}
		if(n==m+k) printf("True\n");
		else printf("False\n");
	}
}