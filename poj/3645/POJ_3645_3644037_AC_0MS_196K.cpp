#include <cstdio>
#include <string>

double Parse() {
	double x, a, b;
	if ( scanf("%lf", &x) ) {
		return x;
	} else {
		scanf ("(");
		if ( scanf ("%lf", &x)==0 ) return 1000000000;
		a = Parse();
		b = Parse();
		scanf (")");
		return x*(a+b) + (1-x)*(a-b);
	}
}

int main () {
	while (true) {
		double ans = Parse();
		if (ans==1000000000) break;
		printf ("%.2lf\n", ans);
	}
	return 0;
}

