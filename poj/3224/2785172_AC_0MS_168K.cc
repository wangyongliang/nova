#include<stdio.h>
int main()
{
	int a[110];
	int n,i,j;
	int k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			a[i]=0;
			for(j=0;j<n;j++) 
			{
				scanf("%d",&k);
				if(k>=3)  a[i]++;
			}
		}
		k=0;
		for(i=0;i<n;i++) if(a[i]>a[k]) k=i;
		printf("%d\n",k+1);
	}
	return 0;
}
