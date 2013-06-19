#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a,b,c,n;
	while(cin>>n)
	{
		if(n<2)	
		{
			while(n>=0)
			{
				n--;
				cin>>a;
			}
			cout<<"YES"<<endl;
		}
		else if(n==2)
		{
			cin>>a>>b>>c;
			if(b*b>=4*a*c)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else
		{
			while(n>=0)
			{
				n--;
				cin>>a;
			}
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
