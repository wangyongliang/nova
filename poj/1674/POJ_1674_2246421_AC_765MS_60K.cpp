#include<stdio.h>
void main()
{
	int n, a[10005], i, cas, j;
	scanf("%d",&cas);
	while(cas--)
	{
		int sum = 0;
		scanf("%d",&n);
		for(i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for(i = 1;i <= n;i++)
		{
			if(a[i]!=i)
				for(j = i + 1;j<=n;j++)
					if(a[j]==i)
					{
					a[j]=a[i];a[i]=i;
					sum++;
					break;
					}
		}
		printf("%d\n",sum);
	}
}

