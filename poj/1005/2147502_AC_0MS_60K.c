#include<stdio.h>
void main()
{
	float p=3.141592653,i,j;
	int n,k;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		scanf("%f %f",&i,&j);
		i=p*(i*i+j*j);
		i/=100.0;
		printf("Property %d: This property will begin eroding in year %d.\n",k,(int)i+1);
	}
	printf("END OF OUTPUT.\n");
}