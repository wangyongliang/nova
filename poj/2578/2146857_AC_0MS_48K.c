#include<stdio.h>
void main()
{
	int a[3],i;
	while(scanf("%d %d %d",&a[0],&a[1],&a[2])!=EOF)
	{
		for(i=0;i<3;i++)
		{
			if(a[i]<168)
				break;
		}
		if(i==3)
			printf("NO CRASH\n");
		else
			printf("CRASH %d\n",a[i]);
	}
}