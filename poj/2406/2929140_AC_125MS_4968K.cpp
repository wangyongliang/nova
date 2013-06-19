#include<stdio.h>
char str[1000000];
int next[1000000];
#include <string.h>
void main()
{

int len;	int i,j;
	while(1)
	{
		scanf("%s",str);
		if(str[0]=='.') return;
		len=strlen(str);
		i=0, j=-1;
		next[0] = -1;
		while(i<len)
		{ 
			if(j==-1||(j>=0&&str[i]==str[j]))
			{
				i++;
				j++;
				next[i]=j;
			}
		else
			j=next[j];
		}
  		i-=j;
        if(len%i==0)i=len/i; else i=1;
		printf("%d\n",i);
	}
}