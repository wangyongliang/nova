#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, i = 1;
	int m, n;
	float sum = 0;

	cin >> a;
	while(cin >> m >> n)
	{
		if(m % 2 == 1 && n % 2 == 1)
			sum = m * n + sqrt(2.0) - 1;
		else
			sum = m * n; 
		printf("Scenario #%d:\n", i++);
		printf("%.2f\n\n", sum);
	}
	return 0;
}
