#include<stdio.h>
#include<string.h>
void tans(char s[])
{
	int i,j,temp;
	j=strlen(s)-1;
	for(i=0;i<=j/2;i++)
	{
		temp=s[i];
		s[i]=s[j-i];
		s[j-i]=temp;
	}
}
void main()
{
	char s[100];
	int i,j,k,l,a[100],b[100],c[200];
	for(i=0;i<200;i++)
		c[i]=0;
	gets(s);
	tans(s);
	for(i=0;s[i];i++)
		a[i]=s[i]-'0';
	k=i;
	gets(s);
	tans(s);
	for(i=0;s[i];i++)
		b[i]=s[i]-'0';
	l=i;
	for(i=0;i<k;i++)
	{
		for(j=0;j<l;j++)
			c[i+j]+=a[i]*b[j];
	}
	for(i=199;c[i]==0;i--);
	if(i==-1)
		printf("0\n");
	else
	{
		for(j=0;j<i+1;j++)
		{
			c[j+1]+=c[j]/10;
			c[j]%=10;
		}
		if(c[i+1])i++;
		for(j=i;j>=0;j--)
			printf("%d",c[j]);
		printf("\n");
	}
}