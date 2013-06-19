#include <stdio.h>
#include <math.h>

char mol[2];
int main()
{
	double T,D,H,h,e;
	while(scanf("%s",mol) && mol[0] != 'E'){
		T = D = H = -1;
		if(mol[0] == 'T')
			scanf("%lf",&T);
		else if(mol[0] == 'D')
			scanf("%lf",&D);
		else
			scanf("%lf",&H);
		scanf("%s",mol);
		if(mol[0] == 'T')
			scanf("%lf",&T);
		else if(mol[0] == 'D')
			scanf("%lf",&D);
		else
			scanf("%lf",&H);
		if(T == -1){
			e = 6.11*exp(5417.7530 * ((1/273.16) - (1/(D+273.16))));
			h = (0.5555)*(e-10.0);
			T = H-h;
		}
		else if(D == -1){
			h = H-T;
			e = h/0.5555 + 10.0;
			e /= 6.11;
			e = log(e);
			e /= 5417.7530;
			e = 1/273.16 - e;
			e = 1/e;
			D = e-273.16;
		}
		else if(H == -1){
			e = 6.11*exp(5417.7530 * ((1/273.16) - (1/(D+273.16))));
			h = (0.5555)*(e-10.0);
			H = T+h;
		}
		printf("T %.1lf D %.1lf H %.1lf\n",T,D,H);
	}
	return 0;
}