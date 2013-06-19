#include<stdio.h>
void main()
{
	int a[20],i,j,k,l;
	while(1)
	{
		i=0;
		while(1)
		{
			scanf("%d",&k);
			if(k==-1)goto lin;
			else if(k==0)break;
			else a[i++]=k;

		}
		for(j=0,k=0;j<i;j++)
		{
			for(l=j;l<i;l++)
			{
				if(2*a[j]==a[l]||a[l]*2==a[j])k++;
			}
		}
		printf("%d\n",k);
	}
lin:;
}