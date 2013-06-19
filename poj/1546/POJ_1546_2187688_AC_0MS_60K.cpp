#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long atoi1(char s[],int n)
{
	long k;
	int i;
	for(i=0;s[i]==' ';i++);
	for(k=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9') k=k*n+s[i]-'0';
		else
		{
			switch(s[i])
			{
			case 'A':k=k*n+10;break;
			case 'B':k=k*n+11;break;
			case 'C':k=k*n+12;break;
			case 'D':k=k*n+13;break;
			case 'E':k=k*n+14;break;
			case 'F':k=k*n+15;break;
			default:break;
			}
		}
	}
	return k;
}
int main()
{
	char s[8],a[20];
	int n,m;
	long k;
	while(scanf("%s%d%d",s,&n,&m)!=EOF)
	{
		k=atoi1(s,n);
		itoa(k,a,m);
		if(strlen(a)>7)printf("  ERROR\n");
		else
		{
			for(n=0;a[n];n++)
			{
				if(a[n]>='a'&&a[n]<='z')
					a[n]='A'+a[n]-'a';
			}
			printf("%7s\n",a);
		}
	}
	return 0;
}