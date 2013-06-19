#include<stdio.h>
#include<string.h>
bool flag[300];
int main()

{
	char s[100];
	int i,j,n;
	char ans[100];
	while(gets(s))
	{
		n=strlen(s);
		for(i=0;i<300;i++) flag[i]=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') s[i]=0;
			else
			{
				if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
				{
					if(flag[s[i]]) s[i]=0;
					else flag[s[i]]=1;
				}
			}
		}
		ans[0]=' ';
		for(i=0,j=1;i<n;i++)
		{
			if(s[i])
			{
				if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) ans[j++]=s[i];
				else if(s[i]==' ')
				{
					if(ans[j-1]!=' ') ans[j++]=' ';
				}
				else 
				{
					if(ans[j-1]==' ') ans[j-1]=s[i];
					else ans[j++]=s[i];
				}
			}
		}
		if(ans[j-1]==' ') ans[j-1]='\0';
		else ans[j]='\0';
		printf("%s\n",ans+1);
	}
	return 0;
}