
#include <cstdlib>
#include <iostream>
using namespace std;
#define INF 1000000000
void work()
{
	int np, ne, sl; scanf("%d%d%d", &np, &ne, &sl);
	int dp[128][128] = {0};
	int pers[128][128] = {0};
	int earn[128], pub[128];	
	for (int i=1; i<=np; i++) {
		pers[i][0] = 0;
		for (int j=1; j<=ne; j++) scanf("%d", &pers[i][j]);
		scanf("%d%d", earn+i, pub+i);
	}
	dp[1][0] = 0;
	for (int i=0; i<=ne; i++) {
		dp[1][i] = ( earn[1]-sl*(i) )*pers[1][i] 
						- pub[1]*(100-pers[1][i]);
	}
	for (int i=2; i<=np; i++) {
		for (int j=0; j<=ne; j++) {
			dp[i][j] = -INF;			
			for (int last = 0; last<=j; last++) {
				int buff = dp[i-1][last] 
						+ ( earn[i]-sl*(j-last) )*pers[i][j-last] 
						- pub[i]*(100-pers[i][j-last]);		 
				if (buff>dp[i][j]) dp[i][j] = buff;				}
		}
	}
	int mx = -INF;
	for ( int i=0; i<=ne; i++) {
		if (dp[np][i]>mx) mx=dp[np][i];
	}
	printf ("%d\n", mx);
	for (int i=0; i<=ne; i++) {
		if (dp[np][i]==mx) printf ("%d ", i);
	}
	printf ("\n");
	return ;
}
int main(int argc, char *argv[])
{
	int t; scanf("%d", &t);
	while (t--) work();
    system("PAUSE");
    return EXIT_SUCCESS;
}
