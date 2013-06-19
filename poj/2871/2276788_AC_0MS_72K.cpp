#include<stdio.h>
int main()
{
	float x,y;
	scanf("%f",&x);
	while(scanf("%f",&y)&&y!=999)
	{
		printf("%.2f\n",y-x);
		x=y;
	}
	printf("End of Output\n");
	return 0;
}