#include<stdio.h>
void main()
{
	int a[770][2],i,j,k,n,l,b[770][3];
	scanf("%d",&n);
	i=0;
	j=n;
	while(j--)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		i++;
	}
	for(i=0,l=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if((a[j][1]-a[i][1])*(a[k][0]-a[i][0])==(a[k][1]-a[i][1])*(a[j][0]-a[i][0]))
				{
					b[l][0]=i+1;
					b[l][1]=j+1;
					b[l++][2]=k+1;
				}
			}
		}
	}
	printf("%d\n",l);
	for(i=0;i<l;i++)
		printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
}