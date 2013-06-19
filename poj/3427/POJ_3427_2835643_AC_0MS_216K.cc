

//pku 1468 1470 的其他方法

//pku 2559,3250 的共同点

//pku1690--pku1697

//pku 1222
#include<stdio.h>
int main()
{
	int n,m;
	int max;
	int a,temp,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		max=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a);
			temp=a%m?m-a%m:a%m;
			max=max<temp?temp:max;
		}
		printf("%d\n",max);
	}
	return 0;
}