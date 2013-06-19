#include<stdio.h>
#include<string.h>
char s[1100];
int a[1100];
char ans[1100];
int div(int n)
{
	int k;
	int  i=0,j=0;
	k=0;
	while(s[i])
	{
		k=k*10+s[i]-'0';
		ans[j]=k/n+'0';
		k%=n;
		i++;
		j++;
	}
	if(!k)
	{
		ans[j]='\0';
		for(i=0;ans[i];i++)
		{
			if(ans[i]!='0')  break;
		}
		strcpy(s,ans+i);
		return 1;
	}
	else return 0;
}
int main()
{
	int i;
	int j;
	while(scanf("%s",s)!=EOF)
	{
		j=0;
		if(s[0]=='-') break;
		if(strlen(s)==1)
		{
			printf("1%s\n",s);
			continue;
		}
		for(i=9;i>1;i--)
		{
			if(strlen(s)==1)
			{
				if(s[0]!='1') a[j++]=s[0]-'0';	
				s[0]='\0';
				break;				
			}
			while(div(i))
			{
				a[j++]=i;
			}
		}
		if(strlen(s)==0)
		{
			for(j--;j>=0;j--) printf("%d",a[j]);
			printf("\n");
		}
		else printf("There is no such number.\n");
	}
	return 0;
}
