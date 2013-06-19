#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double e = 2.7182818284590452354, pi = 3.141592653589793239;
	int n;
	double a;
long double sum=0;
	
	
	int arr[100];
	cin>>n;
	
	for (int i=0;i<=n-1;++i)
	{
		cin>>a;
		if(a==1)
			arr[i]=1;
		else
		arr[i]=.5*log10(2*a*pi)+a*log10(a/e)+1;	
		
	}
	for (int j=0;j<=n-1;++j)
		cout<<arr[j]<<endl;
	
	return 0;
}
 