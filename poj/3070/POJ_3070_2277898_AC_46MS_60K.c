#include<stdio.h>
int main()
{
	__int64 l;
	int i,j,temp;
//	init();
	while(scanf("%I64d",&l)&&l!=-1)
	{
		l%=15000;
		if(l==0) printf("0\n");
		else if(l==1) printf("1\n");
		else
		{
			i=0;
			j=1;
			while(--l)
			{
				temp=i+j;
				temp%=10000;
				i=j;
				j=temp;
			}
		printf("%d\n",j);
		}
	}
	return 0;
}