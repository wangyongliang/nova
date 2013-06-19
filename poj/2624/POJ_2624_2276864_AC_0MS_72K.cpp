#include<stdio.h>
int main()
{
	double a[4][2],x2,x3;
	int i,x1;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[0][0],&a[0][1],&a[1][0],&a[1][1],&a[2][0],&a[2][1],&a[3][0],&a[3][1],&a[4][0],&a[4][1])!=EOF)
	{
		for(x2=x3=i=0;i<4;i++)
		{
			for(x1=i+1;x1<4;x1++) if(a[i][0]==a[x1][0]) x2=i;
		}
		x1=(int)x2;
		for(x2=x3=i=0;i<4;i++) x2+=a[i][0],x3+=a[i][1];
		printf("%.3lf %.3lf\n",x2-a[x1][0]*3,x3-a[x1][1]*3);
	}
	return 0;
}