#include<stdio.h>
void main()
{
	int a[101],i,m,n,k,j;	
	for(i=0;i<101;i++)a[i]=0;
	while(scanf("%d %d",&n,&m)&&(m||n))
	{
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
		for(i=1,j=1,k=a[1];i<101;i++)
		{
			if(k<a[i])
			{
				j=i;
				k=a[i];
			}
			a[i]=0;
		}
		printf("%d\n",k>=m?j:0);
	}
}