#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int n;
int j;
int r[200];
int c[200];

int x1[100];
int y1[100];
int x2[100];
int y2[100];

int findmax( int, int, int, int );

map < int, int > seq;

main (){
	int t;
	int i;
	int xmax;
	int ymax;
	
	scanf ( "%d", &t );
	while ( t -- ){
		scanf ( "%d %d", &xmax, &ymax );
		scanf ( "%d", &n );
		for ( i = 0; i < n; i ++ ){
			scanf ( "%d %d %d %d", x1 + i, y1 + i, x2 + i, y2 + i );
			r[ i * 2 + 0 ] = x1[i];
			r[ i * 2 + 1 ] = x2[i];
			c[ i * 2 + 0 ] = y1[i];
			c[ i * 2 + 1 ] = y2[i];
		}
		sort ( r, r + n * 2 );
		seq.clear();
		for ( i = 0; i < n * 2; i ++ ){
			if ( seq[ r[i] ] == 0 ){
				seq[ r[i] ] = seq.size();
				r[ seq.size() - 1 ] = r[i];
			}
		}
		for ( i = 0; i < n; i ++ ){
			x1[i] = seq[ x1[i] ];
			x2[i] = seq[ x2[i] ];
		}
		xmax = seq.size();

		sort ( c, c + n * 2 );
		seq.clear();
		for ( i = 0; i < n * 2; i ++ )
			if ( seq[ c[i] ] == 0 ){
				seq[ c[i] ] = seq.size();
				c[ seq.size() - 1 ] = c[i];
			}
		for ( i = 0; i < n; i ++ ){
			y1[i] = seq[ y1[i] ];
			y2[i] = seq[ y2[i] ];
		}
		ymax = seq.size();
		
		cout << findmax( 1, 1, xmax, ymax ) << endl;
	}
	
	return 0;
}

int findmax( int xl, int yl, int xh, int yh ){
	int i;
	for ( i = xl + 1; i < xh; i ++ ){
		for ( j = 0; j < n; j ++ )
			if ( x1[j] >= xl && y1[j] >= yl && x2[j] <= xh && y2[j] <= yh )
				if ( x1[j] < i && x2[j] > i )
					break;
		if ( j == n )
			return max( findmax( xl, yl, i, yh ), findmax( i, yl, xh, yh ) );
	}
	
	for ( i = yl + 1; i < yh; i ++ ){
		for ( j = 0; j < n; j ++ )
			if ( x1[j] >= xl && y1[j] >= yl && x2[j] <= xh && y2[j] <= yh )
				if ( y1[j] < i && y2[j] > i )
					break;
		if ( j == n )
			return max( findmax( xl, yl, xh, i ), findmax( xl, i, xh, yh ) );
	}
	
	return ( r[ xh - 1 ] - r[ xl - 1 ] ) * ( c[ yh - 1 ] - c[ yl - 1 ] );
}
