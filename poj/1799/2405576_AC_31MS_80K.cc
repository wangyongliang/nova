#include<stdio.h>
#include<math.h>
#define pi 3.141592653

int main()
{
	double angel,R,r;
	int n,t,i=1;
	scanf("%d",&t);
	while(i<=t)
	{
		scanf("%lf%d",&R,&n);
		angel=pi/n;
		angel=sin(angel);
		printf("Scenario #%d:\n%.3lf\n",i,angel*R/(1+angel));
		if(i!=t) printf("\n");
		i++;
	}
	return 0;
}

