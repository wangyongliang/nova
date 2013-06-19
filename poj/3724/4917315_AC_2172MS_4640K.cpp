
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
#define maxn 100000
int n;
int a[10];
int digit[20];
double y[20];
double x[20];
double dis[maxn];
int ans[maxn][10];
int num;
int Enum( int, int );

int main(){
	int i, j;
	char readin[100];
	
	while( scanf ( "%d", &n ) != EOF ){
		for ( i = 0; i < n; i ++ ){
			scanf ( "%lf %lf", x + i, y+i );
		//	y[i] = readin;
		}
		num=0;
		Enum( 0, 1 );
		int  ct=0;
		for(i=0;i<num;i++)
		{
			if(dis[i]<dis[ct])  ct=i;
		}
		
		for(i=0;i<10;i++) cout<<ans[ct][i]<<endl;
		//cout<<endl;
	}
	
	return 0;
}

int Enum( int d, int s ){
	int i;
	if ( d == 10 ){
		double cnt;
		int j;
		dis[num]=0.0;
		for ( i = 0; i < n; i ++ ){
			cnt = 0.0;
			
			for ( j = 0; j < 10; j ++ )
			{
				cnt += exp( a[j] * x[i] );
				ans[num][j]=a[j];
			}
			dis[num]+=fabs(cnt-y[i]);
		}
		num++;
		return 0;
	}
	for ( i = s; i <= 10; i ++ ){
		a[d] = i;
		if ( Enum( d + 1, i ) == 1 )
			return 1;
	}
	
	return 0;
}

