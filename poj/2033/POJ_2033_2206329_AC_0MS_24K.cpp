#include<stdio.h>
int main()
{
	char s[5050];
	int i;
	long a,b,c,temp;
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='0')
			break;
		else
		{
			c=a=b=1;
			
			for(i=1;s[i];i++)
			{
				if(s[i]=='0') c=b;
				else
				{
					if((s[i-1]-'0')*10+s[i]-'0'>=10&&(s[i-1]-'0')*10+s[i]-'0'<=26&&s[i+1]!='0')
						c=a+b;
					else
					{
						c=b;
					}
					a=b;
					b=c;
				}
			}
		}
		printf("%ld\n",c);
	}
	return 0;
}