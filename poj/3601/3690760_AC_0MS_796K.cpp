#include <stdio.h>

int a[128], b[128], k[128];
int main () {
	int n, m, i;
	while (scanf ("%d%d", &n, &m)!=EOF) 
	{
		for ( i=0; i<n; i++ ) scanf ("%d", k+i);
		b[0]=k[0]%m; a[0]=(k[0]==1)?1:((2*k[0]-1)%m);
		for ( i=1; i<n; i++ )
		{
			b[i]=(k[i]+2*b[i-1])%m;
			if (k[i]==1) a[i]=(2*b[i-1]+1)%m;
			else a[i]=(2*b[i-1]+2*k[i]+a[i-1])%m;
		}
		printf ("%d\n", a[n-1]);
	}
	return 0;
}
