#include<stdio.h>
#include<string.h>
char s[1000];
int b[1000];
void main()
{
	char a[1000];
	int i,j,k,l,m;
	while(1)
	{
		gets(s);
		if(s[0]=='-')
			break;
		else if(strlen(s)==1&&s[0]=='0')
			printf("10\n");
		else if(strlen(s)==1&&s[0]=='1')
			printf("11\n");
		else
		{
			for(i=0;i<1000;i++)
				b[i]=0;
			l=0;
			j=9;
			while(j>1)
			{
				k=0;
				if(strlen(s)==1&&s[0]=='1')
					break;
				for(i=0;s[i];i++)
				{
					k=k*10+s[i]-'0';
					a[i]=k/j+'0';
					k%=j;
				}
				a[i]='\0';
				if(k==0)
				{
					for(i=0;a[i]=='0';i++);
					strcpy(s,&a[i]);
					b[l++]=j;
				}
				else
					j--;
			}
			if(strlen(s)==1&&s[0]=='1')
				k=0;
			else 
				k=1;
			if(k)
				printf("There is no such number.\n");
			else
			{
				for(i=999;b[i]==0;i--);
				if(i==0)
					printf("1%d\n",b[0]);
				else
				{
					for(;i>=0;i--)
						printf("%d",b[i]);
					printf("\n");
				}
			}
		}
	}
}
