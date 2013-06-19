#include<stdio.h>
#include<math.h>
struct node
{
	double x,y;
}p[10];
void  circle_center(int i,int j,int k,double  &r,double &x,double &y)  
{  
	double  x1,x2,x3,y1,y2,y3; 
/*	int t=cross(i,j,k);
	if(!t) 
	{
		r=100000.0;
		return;
	} */
	x1  =  p[i].x;  
	x2  =  p[j].x;  
	x3  =  p[k].x;  
	y1  =  p[i].y;  
	y2  =  p[j].y;  
	y3  =  p[k].y;  
	x=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2*(x3-x1)*(y2-y1)-2*((x2-x1)*(y3-y1)));  
	y=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2*(y3-y1)*(x2-x1)-2*((y2-y1)*(x3-x1)));  
	r=(x1-x)*(x1-x)+(y1-y)*(y1-y); 
	r=sqrt(r);
}
double inf=1e-6;
void print(double x)
{
	if(fabs(x)<inf) x=0.0;
	if(x>=0.0) printf(" + ");
	else printf(" - ");
	printf("%.3lf",fabs(x));
}
int main()
{
	int i,j;
	double r,x,y;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)!=EOF)
	{
		circle_center(0,1,2,r,x,y);
		x=-x;
		y=-y;
		printf("(x");
		print(x);
		printf(")^2 + ");
		printf("(y");
		print(y);
		printf(")^2 = %.3lf^2\n",fabs(r));		
		r=pow(r,2)-pow(x,2)-pow(y,2);
		x=2*x;
		y=2*y;
		printf("x^2 + y^2");
		print(x);
		printf("x");
		print(y);
		printf("y");
		print(-r);
		printf(" = 0\n\n");
	}
	return 0;
}