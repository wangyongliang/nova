#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
void solve()
{
	int i, j, k;
	scanf( "%d %d" , &n , &m );
	k = n/m;
	for( i = 1;i <= k;i++ )
		for( j = 1;j <= m;j++ ) printf("%d " , j );
	n = n%m;
	for( i = 0;i < n;i++ )
		printf("%d " , (i*m)/n + 1 );
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
