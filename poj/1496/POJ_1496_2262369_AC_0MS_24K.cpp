#include<stdio.h>
#include<string.h>
long com(int x,int y)
{
	long sum=1;
	int i;
	for(i=0;i<y;i++)
	{
		sum*=(x-i);
	}
	for(;y;y--) sum/=y;
	return sum;
}
int main()
{
	char s[11];
	long n;
	int i,j;
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;s[i+1];i++) 
		{
			if(s[i]>=s[i+1]) break;
		}
		if(s[i+1]) printf("0\n");
		else
		{
			i=strlen(s);
			for(--i,n=0;i;i--) 
				n+=com(26,i);
			for(i=0;s[i];i++)
			{
				if(i==0)j='a';
				else j=s[i-1]+1;
				for(;j<s[i];j++)
				{
					n+=com('z'-j,strlen(s)-i-1);
				}
			}
			printf("%ld\n",n+1);
		}
	}
	return 0;
}