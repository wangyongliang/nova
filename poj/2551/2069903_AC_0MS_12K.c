#include<stdio.h>
void main()
{
	int n,mod=0,k=0,flag;
	while(scanf("%d",&n)!=EOF)
	{
		for(flag=1;flag<=n;flag*=10)
		{
			mod+=flag;
			k++;
		}
		mod%=n;
		while(1)
		{
			if(mod==0)
				break;
			else
			{
				flag%=n;
				mod+=flag;
				mod%=n;
				flag*=10;
				k++;
			}
		}
			printf("%d\n",k);
			k=0;
			mod=0;
	
	}
}