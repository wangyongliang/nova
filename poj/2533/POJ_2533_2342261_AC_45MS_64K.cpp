#include<stdio.h>
void main()
{
	int a[1005],b[1005];
	int i,j,n,min;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i),b[i]=0;
		b[0]=1;
		for(i=0;i<n;i++)
		{
			min=-1;
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i])
				{
					if(min==-1) min=j;
					else
					{
						min=b[j]>b[min]?j:min;
					}
				}
			}
			if(min!=-1)
			b[i]=b[min]+1;
else b[i]=1;
		}
		for(j=b[0],i=0;i<n;i++) j=j>b[i]?j:b[i];
		printf("%d\n",j);
	}
}
