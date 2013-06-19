#include <stdio.h>
void main(){
	int i=1;
	float p=3.1415927;
	int b;
	float a,d,e,c;
	scanf ("%f %d %f",&a,&b,&c);
	while (b!=0){
		d=a*b*p/5280/12;
		e=a*b/c*p*3600/5280/12;
		printf("Trip #%d: %.2f %.2f\n",i,d,e);
		i++;
	    scanf("%f %d %f",&a,&b,&c);
	}
}
