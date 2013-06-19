#include<stdio.h>
#include<string.h>
void main()
{

	int a[100],i,j,k;
	char s[100];
	while(1)
	{
		gets(s);
		if(strlen(s)==3&&s[0]=='0'&&s[1]==' '&&s[2]=='0')
			break;
		else
		{
			for(i=0;i<99;i++)a[i]=0;
			for(i=0;s[i]!=' ';i++);
			for(j=99,k=i-1;k>=0;k--)
				a[j--]=s[k]-'0';
			for(j=99,k=strlen(s)-1;k>i;k--)
				a[j--]+=s[k]-'0';
			for(j=99,i=0;j>=0;j--)
			{
				if(a[j]>9)
				{
					a[j-1]+=a[j]/10;
					a[j]%=10;
					i++;
				}
			}
		}
		if(i==0)
			printf("No carry operation.\n");
		else if(i==1)printf("%d carry operation.\n",i);
		else
			printf("%d carry operations.\n",i);
	}
}