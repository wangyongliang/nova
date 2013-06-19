// a[i]记录，b[]记录是否已经出过
#include<stdio.h>
int main()
{
	int a[13],b[13];
	int n,i,j,k,l;
	scanf("%d",&n);
	while(n--)
	{
		j=0;
		scanf("%d",&k);
		for(i=0;i<k;i++) a[i]=b[i]=0;
		for(i=1;i<=k;i++)
		{
			for(l=0;l<i;j++)
			{
				j%=k;
				if(!b[j]) l++;
			}
			for(;;j++)
			{
				j%=k;
				if(!b[j]) 
				{
					a[j]=i;
					b[j]=1;
					break;
				}
			}
		}
		printf("%d",a[0]);
		for(i=1;i<k;i++) printf(" %d",a[i]);
		printf("\n");
	}
}
