#include<stdio.h>
void main()
{
	int a[101],i,m,n,k,j;
	while(scanf("%d %d",&n,&m)&&(m||n))
	{
		for(i=0;i<101;i++)a[i]=0;
		while(n--)
		{
			scanf("%d",&k);
			{
				for(i=0;i<k;i++)
				{
					scanf("%d",&j);
					a[j]++;
				}
			}
		}
		for(i=1,j=1;i<101;i++)
		{
			if(a[j]<a[i])j=i;
		}
		printf("%d\n",a[j]>=m?j:0);
	}
}