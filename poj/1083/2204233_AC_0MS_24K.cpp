#include<stdio.h>
void main()
{
	int a[401],i,j,n,k,temp;
	scanf("%d",&n);
	
	while(n--)
	{for(i=0;i<401;i++)a[i]=0;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&i,&j);
			if(i==j) continue;
			if(i>j)
			{
			temp=i;
			i=j;
			j=temp;
			}
			i-=!(i%2);
			j+=j%2;
			for(temp=i;temp<=j;temp++) a[temp]++;
		}
		for(i=0,temp=0;i<401;i++)
		{
			temp=a[i]>temp?a[i]:temp;
		}
		printf("%d\n",temp*10);
	}
}