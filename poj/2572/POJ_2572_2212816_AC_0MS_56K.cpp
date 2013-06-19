#include<stdio.h>
#include<string.h>
void main()
{
	char s[30],c;
	int i,j=1,k,a[3];
	k=a[0]=0;
	while(1)
	{
		c=getchar();
		if(c=='+'||c=='=') k++,j=1,a[k]=0;
		else if(c==10)
		{
			if(a[0]+a[1]==a[2]) printf("True\n");
			else printf("False\n");
			if(!a[0]&&!a[1]&&!a[2])break;
			k=a[0]=0;
			j=1;
		}
		else
		{
			a[k]+=(c-'0')*j;
			j*=10;
		}
	}
}