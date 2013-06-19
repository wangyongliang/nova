#include <iostream>
using namespace std;

int beg[2][251][251];
int end[2][251][251];
int pos[3][600];
int top[3];

main(){
	int modulo = 20090305;
	long long cnt;
	int t;
	int ra, rb, rc;
	int half, n;
	int i, j, k;
	int a, b, c;
	char readin[600];
	
	scanf ( "%d", &t );
	while ( t -- ){
		scanf ( "%d %d %d", &ra, &rb, &rc );
		scanf ( "%s", readin );
		n = strlen( readin );
		top[0] = top[1] = top[2] = 0;
		for ( i = 0; readin[i]; i ++ )
			pos[ readin[i] - 'A' ][ top[ readin[i] - 'A' ] ++ ] = i;
		
		half = n / 2;
		beg[0][0][0] = 1;
		end[0][0][0] = 1;
		for ( i = 0; i < half; i ++ ){
			for ( j = 0; j <= i + 1 && j <= top[0]; j ++ )
				for ( k = 0; k <= i - j + 1 && k <= top[1]; k ++ )
					beg[ ( i + 1 ) % 2 ][j][k] = 0;
			for ( j = 0; j <= i && j <= top[0]; j ++ )
				for ( k = 0; k <= i - j && k <= top[1]; k ++ ){
					a = j;
					b = k;
					c = i - j - k;
					if ( a < top[0] && abs( pos[0][a] - i ) <= ra )
						beg[ ( i + 1 ) % 2 ][ a + 1 ][b] = ( beg[ ( i + 1 ) % 2 ][ a + 1 ][b] + beg[ i % 2 ][j][k] ) % modulo;
					if ( b < top[1] && abs( pos[1][b] - i ) <= rb )
						beg[ ( i + 1 ) % 2 ][a][ b + 1 ] = ( beg[ ( i + 1 ) % 2 ][a][ b + 1 ] + beg[ i % 2 ][j][k] ) % modulo;
					if ( c < top[2] && abs( pos[2][c] - i ) <= rc )
						beg[ ( i + 1 ) % 2 ][a][b] = ( beg[ ( i + 1 ) % 2 ][a][b] + beg[ i % 2 ][j][k] ) % modulo;
				}
		}
//		cout << beg[1][1][0] << " " << beg[1][0][1] << " " << beg[1][0][0] << " " << endl;
//		cout << beg[0][2][0] << " " << beg[0][1][1] << " " << beg[0][1][0] << " " << beg[0][0][2] << " " << beg[0][0][1] << " " << beg[0][0][0] << " " << endl;
		for ( i = 0; i < n - half; i ++ ){
			for ( j = 0; j <= i + 1 && j <= top[0]; j ++ )
				for ( k = 0; k <= i - j + 1 && k <= top[1]; k ++ )
					end[ ( i + 1 ) % 2 ][j][k] = 0;
			for ( j = 0; j <= i && j <= top[0]; j ++ )
				for ( k = 0; k <= i - j && k <= top[1]; k ++ ){
					a = j;
					b = k;
					c = i - j - k;
					if ( a < top[0] && abs( pos[0][ top[0] - a - 1 ] - ( n - i - 1 ) ) <= ra )
						end[ ( i + 1 ) % 2 ][ a + 1 ][b] = ( end[ ( i + 1 ) % 2 ][ a + 1 ][b] + end[ i % 2 ][j][k] ) % modulo;
					if ( b < top[1] && abs( pos[1][ top[1] - b - 1 ] - ( n - i - 1 ) ) <= rb )
						end[ ( i + 1 ) % 2 ][a][ b + 1 ] = ( end[ ( i + 1 ) % 2 ][a][ b + 1 ] + end[ i % 2 ][j][k] ) % modulo;
					if ( c < top[2] && abs( pos[2][ top[2] - c - 1 ] - ( n - i - 1 ) ) <= rc )
						end[ ( i + 1 ) % 2 ][a][b] = ( end[ ( i + 1 ) % 2 ][a][b] + end[ i % 2 ][j][k] ) % modulo;
				}
		}
//		cout << end[1][1][0] << " " << end[1][0][1] << " " << end[1][0][0] << " " << endl;
//		cout << end[0][2][0] << " " << end[0][1][1] << " " << end[0][1][0] << " " << end[0][0][2] << " " << end[0][0][1] << " " << end[0][0][0] << " " << endl;
		cnt = 0LL;
		for ( j = 0; j <= half && j <= top[0]; j ++ )
			for ( k = 0; k <= half - j && k <= top[1]; k ++ )
				if ( half - j - k <= top[2] )
					cnt = ( cnt + ( ( long long )beg[ half % 2 ][j][k] ) * ( ( long long )end[ ( n - half ) % 2 ][ top[0] - j ][ top[1] - k ] ) ) % modulo;
		printf( "%I64d\n", cnt );
	}
	
	return 0;
}

