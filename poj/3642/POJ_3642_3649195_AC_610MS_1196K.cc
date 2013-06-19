#include <iostream>
using namespace std;

long long d[17][17];
long long carcost[32768];
long long cost[32768], cost2[32768];

main() {
  int i, j, k, x, y, z, n, m;
	while (cin >> n >> m) {
	  for (i = 0; i <= n+1; i++)
		for (j = 0; j <= n+1; j++)
		  d[i][j] = (i==j) ? 0 : 1000000000000LL;
    for (i = 0; i < m; i++) {
		  cin >> x >> y >> z;
			d[x][y] <?= z; d[y][x] <?= z;
		}
	  for (k = 0; k <= n+1; k++)
	  for (i = 0; i <= n+1; i++)
		for (j = 0; j <= n+1; j++)
		  d[i][j] <?= d[i][k] + d[k][j];
		for (i = 0; i < (1<<n); i++)
		  cost[i] = cost2[i] = carcost[i] = 1000000000000LL;
		for (int a1 = 1; a1 <= n; a1++)
		for (int a2 = 1; a2 <= n; a2++)
		for (int a3 = 1; a3 <= n; a3++)
		for (int a4 = 1; a4 <= n; a4++)
		for (int a5 = 1; a5 <= n; a5++)
		  carcost[((1<<a1)|(1<<a2)|(1<<a3)|(1<<a4)|(1<<a5)) >> 1] <?=
			  d[0][a1] + d[a1][a2] + d[a2][a3] + d[a3][a4] + d[a4][a5] + d[a5][n+1] +
				5 * (1 + (a2 != a1) + (a3 != a2) + (a4 != a3) + (a5 != a4));
    cost[0] = 0;
    for (i = 0; i < (n+4)/5; i++) {
		  for (j = 0; j < (1<<n); j++) if (carcost[j] < 1000000000000LL)
			for (k = (1<<n)-1; (k &= ~j) >= 0; k--)
			  cost2[k|j] <?= cost[k] >? carcost[j];
      memcpy(cost, cost2, sizeof(cost));
		}
		cout << cost[(1<<n)-1] << endl;
	}
}
