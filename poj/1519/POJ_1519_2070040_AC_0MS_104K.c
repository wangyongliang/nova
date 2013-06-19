#include<stdio.h>
void main()
{
	int i,sum;
	char s[100000];
	while(scanf("%s",s))
	{
		sum=0;
		if(s[0]=='0')
			break;
		else
		{
			for(i=0;s[i];i++)
			{
				sum+=s[i]-'0';
			}
			sum%=9;
			if(sum!=0)
				printf("%d\n",sum);
			else
				printf("9\n");
		}
	}
}