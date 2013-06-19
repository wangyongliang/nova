#include <stdio.h>

int main () {
	int n, i, j, k; 
	char a[2][5]; 
	scanf ("%d", &n);
	for ( i=0; i<n; i++ ) {
		int b[2]={0}, c[4]={0};
		scanf ("%s%s", a[0], a[1]);
		for ( j=0; j<4; j++ ) {
			if ( a[0][j]==a[1][j] ) {
				b[0]++; c[j]=1;
			}
		}
		for ( j=0; j<4; j++ ) {
			if (c[j]==0) {
				for ( k=0; k<4; k++ ) {
					if (c[k]==0 && a[0][j]==a[1][k]) { b[1]++; break; }
				}
			}
		}
		printf ("%dA%dB\n", b[0], b[1]);
	}
	return 0;
}
