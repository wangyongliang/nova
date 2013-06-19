#include<stdio.h>
int main()
{
	char s[256];
	int i;
	long sum;
	while(1)
	{
		gets(s);
		if(s[0]=='#') break;
		else
		{
			for(sum=i=0;s[i];i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					sum+=(s[i]-'A'+1)*(i+1);
				}
			}
			printf("%ld\n",sum);
		}
	}
}