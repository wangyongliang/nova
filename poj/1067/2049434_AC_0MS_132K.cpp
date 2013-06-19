#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double alpha = (1.0 + sqrt(5.0)) / 2.0;
	double beta  = (3.0 + sqrt(5.0)) / 2.0;
	int big, small, n, temp1, temp2;
	while(cin>>big>>small)
	{
		if(big < small)
			swap(big, small);
		n = ceil(big / beta);
		temp1 = alpha * n;
		temp2 = beta  * n;
		if(small == temp1 && big == temp2)
			cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
 
