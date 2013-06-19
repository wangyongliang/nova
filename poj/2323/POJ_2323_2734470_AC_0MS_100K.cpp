#include<stdio.h>
__int64 a[19][19*18/2]={0};
int main()
{
	int i,j;
	int k;
	a[1][0]=1;
	for(i=1;i<18;i++)
	{
		for(j=0;j<=i*(i-1)/2;j++)
		{
			for(k=0;k<=i;k++) a[i+1][j+k]+=a[i][j];
		}
	}
	while(scanf("%d%d",&i,&j)&&(i+j))
	{
		printf("%I64d\n",a[i][j]);
	}
	return 0;
}
