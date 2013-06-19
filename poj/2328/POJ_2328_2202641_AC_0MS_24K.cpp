#include<stdio.h>
#include<string.h>
void main()
{
	int n,a[11],i,flag;
	char s[15];
	for(i=0;i<11;i++)a[i]=1;
	while(scanf("%d",&n)&&n)
	{
		flag=1;
		
		scanf("%*s%s",s);
		if(s[strlen(s)-1]=='h')
		{

			for(i=n;i<11;i++)
				a[i]=0;
		}
		else if(s[strlen(s)-1]=='w')
		{
			for(i=1;i<=n;i++)
				a[i]=0;
		}
		else
		{
			if(!a[n])
				printf("Stan is dishonest\n");
			else
				printf("Stan may be honest\n");
			for(i=0;i<11;i++)a[i]=1;
		}
	}
}