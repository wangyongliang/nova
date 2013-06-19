#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
 
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
typedef vector<int> VI;
typedef vector<string> VS;
typedef __int64 ll;
//data
int degree[ 500010 ] = { 0 };
int uset[ 500010 ] = { -1 };
int col_num = 0;
class Num{
public:
	int index;
	Num* p[ 26 ];
public:
	Num()
	{
		index = -1;
		FOR( i, 0, 25 ) p[ i ] = NULL;
	}
};

Num* ROOT;

int GetNum( char * str )
{
	int num;
	Num* P = ROOT;
	FOR( i, 0, strlen( str ) - 1 )
	{
		int index = str[ i ] - 'a';
		if( P->p[ index ] == NULL )
		{
			P->p[ index ] = new Num();
		}
		P = P->p[ index ];
	}
	if( P->index == -1 ) P->index = col_num++;
	return P->index;
}

int uset_find( int inode )
{
	if( uset[ inode ] < 0 ) return inode;
	int j = inode;
	while( uset[ j ] >= 0 )
	{
		j = uset[ j ];
	}
	uset[ inode ] = j;
	return j;
}

int uset_union( int r1, int r2 )
{
	if( r1 == r2 ) return 0;
	if( uset[ r1 ] > uset[ r2 ] ) swap( r1, r2 );
	uset[ r1 ] += uset[ r2 ];
	uset[ r2 ] = r1;
	return 0;
}

bool odd( int n )
{
	return n % 2;
}

int main()
{
	ROOT = new Num();
	memset( uset, -1, sizeof( uset ) );
	memset( degree, 0, sizeof( degree ) );
	char color1[ 20 ];
	char color2[ 20 ];
	int flag=0;
	col_num = 0;
	while( scanf( "%s%s", color1, color2 ) != EOF ){
		int i = GetNum( color1 );//获取颜色编号 O(1)
		int j = GetNum( color2 );//O(1)
		++degree[ i ];
		++degree[ j ];//记录度数	
		uset_union( uset_find( i ), uset_find( j ) ); 
		flag=1;
	}//while
	if(flag){
	if( uset[ uset_find( 0 ) ] + col_num != 0 )
	{
		printf( "Impossible\n" );
		return 0;
	}
	int odd_num = count_if( degree, degree + col_num, odd );
	if( odd_num <= 2 )
		printf( "Possible\n" );
	else
		printf( "Impossible\n" );
	}
	else printf("Possible\n");
	return 0;
}