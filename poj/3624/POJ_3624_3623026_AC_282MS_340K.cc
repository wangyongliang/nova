#include <cstdio>
#include <cstring>

int bes[12880], n, m, a, b, i, j;

int main () {
    scanf ("%d%d", &n, &m);
    memset (bes, 0, sizeof (bes));
    for (i=0; i<n; i++){
	scanf ("%d%d", &a, &b);
	for (j=m; j>=a; j--)
	    bes[j]>?=bes[j-a]+b;
    }
    printf ("%d\n", bes[m]);
    return 0;
}

