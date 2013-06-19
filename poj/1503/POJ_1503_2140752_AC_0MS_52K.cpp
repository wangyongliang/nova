#include<stdio.h>
#include<string.h>
void main()
{
	char s[120][120];
	int a[120],i=0,k,j;
	while(1)
	{
		gets(s[i]);
		if(strlen(s[i])==1&&s[i][0]=='0')
			break;
		i++;
	}
	for(j=0;j<120;j++)
		a[j]=0;
	for(i--;i>=0;i--)
	{
		for(j=119,k=strlen(s[i])-1;k>=0;k--,j--)
			a[j]+=s[i][k]-'0';
	}
	for(j=119;j>=0;j--)
	{
		a[j-1]+=a[j]/10;
		a[j]%=10;
	}
	for(j=0;a[j]==0;j++);
	for(;j<120;j++)
		printf("%d",a[j]);
	printf("\n");

}