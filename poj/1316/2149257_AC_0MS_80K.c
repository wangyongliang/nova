#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int jisuan(int n)
{
	char s[5],i,sum=0;
	itoa(n,s,10);
	for(i=0;s[i];i++)
		sum+=s[i]-'0';
	return n+sum;
}
void main()
{
	int a[10001]={0},i,j;
	for(i=1;i<=10000;i++)
	{
		j=jisuan(i);
		if(j<=10000)
			a[j]=1;
	}
	for(i=1;i<=10000;i++)
	{
		if(!a[i])
			printf("%d\n",i);
	}
}