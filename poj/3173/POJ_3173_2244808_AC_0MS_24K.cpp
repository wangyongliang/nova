#include<stdio.h>
int main()
{
	int n,s,a[20],i,j;
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		for(i=1,a[0]=s;i<n;i++)  a[i]=(a[i-1]+i)%9?(a[i-1]+i)%9:9;
		printf("%d",a[0]);
		for(i=1;i<n;i++) printf(" %d",a[i]);
		printf("\n");
		for(i=1;i<n;i++)
		{
			printf(" ");
			for(j=1;j<i;j++) printf("  ");
			for(j=i;j<n;j++)
			{
				a[j]=(a[j]+1)%9?(a[j]+1)%9:9;
				printf(" %d",a[j]);
			}
			printf("\n");
		}
	}
}