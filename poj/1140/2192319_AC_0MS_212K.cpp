#include<stdio.h>
#include<string.h>
void main()
{
	int a[20000],b[20000];
	int n,m,i,j;
	while(scanf("%d %d",&n,&m)&&(n||m))
	{
		i=j=0;
		memset(a,0,sizeof(int)*20000);
		while(1)
		{
			if(a[n])break;
			else a[n]=i+1;
			n*=10;
			b[i++]=n/m;
			n%=m;
		}
		printf(".");
		if(n==0)
		{	
			for(j=0;j<i-1;j++)
			{
				printf("%d",b[j]);
				if(j%50==48)
				printf("\n");
			}
			if((j-1)%50!=48) printf("\n");
			printf("This expansion terminates.\n");
		}
		else
		{
			for(j=0;j<i;j++)
			{
				printf("%d",b[j]);
				if(j%50==48)
				printf("\n");
			}
			if((j-1)%50!=48) printf("\n");
			printf("The last %d digits repeat forever.\n",i-a[n]+1);
		}
	}
}