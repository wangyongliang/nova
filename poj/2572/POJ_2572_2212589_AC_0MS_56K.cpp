#include<stdio.h>
#include<string.h>
void main()
{
	char s[30];
	int a[10],b[10];
	int i,j,n,m;
	while(1)
	{
		gets(s);
		if(!strcmp(s,"0+0=0")) 
		{
			printf("True\n");
			break;
		}
		for(i=0;i<10;i++)a[i]=b[i]=0;
		for(i=0;s[i]!='+';i++) a[i]=s[i]-'0';
		for(j=0,i++;s[i]!='=';i++) b[j++]=s[i]-'0';
		for(n=0,j=1,i++;s[i];i++)
		{
			n+=(s[i]-'0')*j;
			j*=10;
		}
		for(i=0;i<10;i++) b[i]+=a[i];
		for(i=0;i<10;i++) b[i+1]+=b[i]/10,b[i]%=10;
		for(i=m=0,j=1;i<10;i++)
		{
			m+=j*b[i];
			j*=10;
		}
		if(n==m) printf("True\n");
		else printf("False\n");
	}
}