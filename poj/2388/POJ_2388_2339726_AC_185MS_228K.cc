#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXN 10000
using namespace std;
int main()
{
   
   long int milk[MAXN], N;
   long int result;
   int i;
   while(cin>>N)
   {
	   for(i=0;i<N;i++)
		   cin>>milk[i];
	   result=N/2;
	   nth_element(milk, milk + result, milk + N);
	   cout<<milk[result]<<endl;
   }
   return 0;
}
