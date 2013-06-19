
#include<stdio.h>
#include<string.h>
int a[3]={9,3,7};
int  main()
{
	char s[20];
	int i,j,n,sum,t,num=1,k;
	scanf("%d",&t);
	
	while(num<=t)
	{
		sum=0;
		scanf("%s",s);
		for(i=strlen(s)-1,k=0;i>=0;i--,k++)
		{
			if(s[i]=='?') j=k;
			else
			{
				sum+=(s[i]-'0')*a[k%3];
			}
		}
		sum%=10;
		for(i=0;i<10;i++)
		{
			if((a[j%3]*i+sum)%10==0) break;
		}
		printf("Scenario #%d:\n",num);
		for(j=0;s[j];j++)
		{
			if(s[j]=='?') printf("%d",i);
			else printf("%c",s[j]);
		}
		printf("\n\n");
		num++;
	}
	return 0;
}