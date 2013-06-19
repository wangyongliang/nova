#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int next[100010];

void getnext( char * );
int getMRSL( char * );	//	get Minimum Repeating Substring Length
int gcd( int, int );

char str[10100];
char a[10100][80];
int b[10100];

main(){
	int n, m, i, j;
	int LCM, now, Column, Row;
	
	while( scanf ( "%d %d", &n, &m ) != EOF ){
		for ( i = 0; i < n; i ++ )
			scanf ( "%s", a[i] );
		LCM = 1;
		for ( i = 0; i < m; i ++ ){
			if ( LCM >= n ){
				LCM = n;
				break;
			}
			for ( j = 0; j < n; j ++ )
				str[j] = a[j][i];
			str[j] = 0;
			now = getMRSL( str );
			LCM = ( LCM / gcd( LCM, now ) ) * now;
		}
		Column = LCM;
		
		LCM = 1;
		for ( i = 0; i < n; i ++ ){
			if ( LCM >= m ){
				LCM = m;
				break;
			}
			now = getMRSL( a[i] );
			LCM = ( LCM / gcd( LCM, now ) ) * now;
		}
		
		Row = LCM;
		printf( "%d\n", Column * Row );
	}
	
	return 0;
}

void getnext( char* str ){
	int i = -1, j = 0;
	int len = strlen( str );
	next[0] = -1;
	
	while( j <= len ){
		if ( i == -1 || str[i] == str[j] ){
			i ++;
			j ++;
			next[j] = i;
		}
		else
			i = next[i];
	}
	
}

int getMRSL( char * str ){
	getnext( str );
	int i;
	int len = strlen( str );
	if ( next[len] * 2 >= len ){
		for ( i = len; i >= 0; i -- )
			if ( next[i] * 2 == i )
				break;
		return next[ i - 1 ] + 1;
	}
	
	return len - next[ len ];
}

int gcd( int a, int b ){
	if ( a > b )
		return gcd( b, a );
	if ( a == 0 )
		return b;
	return gcd( b % a, a );
}
