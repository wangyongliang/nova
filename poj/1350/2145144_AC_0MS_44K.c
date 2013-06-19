#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char s[])
{
	int i,j,k;
	for(i=0;s[i];i++)
	{
		k=i;
		for(j=i+1;s[j];j++)
		{
			if(s[j]>s[k])
				k=j;
		}
		if(k!=i)
		{
			j=s[i];
			s[i]=s[k];
			s[k]=j;
		}
	}
}
void change(char a[])
{
	int i,j,len;
	len=strlen(a);
	for(i=0;i<len/2;i++)
	{
		j=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=j;
	}
}
void main()
{
	char c[10];
	int i,j,n;
	while(1)
	{
		gets(c);
		if(c[0]=='-')
			break;
		else
		{
			if(strlen(c)!=4)
				printf("N=%s:\nNo!!\n",c);
			else
			{
				if(c[0]==c[1]&&c[2]==c[3]&&c[1]==c[2])
					printf("N=%s:\nNo!!\n",c);
				else
				{
					j=0;
					n=atoi(c);	
					printf("N=%d:\n",n);
					while(n!=0&&n!=6174)
					{
						sort(c);
						n=atoi(c);
						change(c);
						i=atoi(c);
						printf("%d-%d=%d\n",n,i,n-i);
						n-=i;
						itoa(n,c,10);
						j++;
					}
					printf("Ok!! %d times\n",j);
				}
			}
		}
	}
}