#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n, k, i;
	int data[1024];

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		for (i = 0 ; i < n ; i++)
			scanf("%d", data + i);
		while (next_permutation(data, data + n), --k);
		for (i = 0 ; i < n ; i++)
			printf("%d%c", data[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}
