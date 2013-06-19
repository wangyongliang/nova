#include<stdio.h>
void main()
{
	int a[101],i,j,k,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		for(i=0;i<=k;i++)a[i]=1;
		for(i=2;i<=k;i++)
		{
			for(j=i;j<=k;j+=i)
				a[j]=1-a[j];
		}
		for(i=1,j=0;i<=k;i++)
			if(a[i])j++;
			printf("%d\n",j);
	}
}