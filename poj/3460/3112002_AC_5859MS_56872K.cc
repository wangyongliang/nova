#include <iostream>
using namespace std;

struct vector{
	int value[15];
};

struct vector moved[313601];
struct vector movef[313601];
struct vector moveb[313601];
int code[313601];
int top;
int n;

void move ( struct vector );
int cmp ( const void *, const void *);
int vcmp ( struct vector, struct vector );

main (){
	int t;
	int i, j, k;
	int a;
	int m;
	int m1, m2;
	struct vector result;
	struct vector vi;
	int topf, topb;
	
	cin >> t;
	while ( t -- ){
		cin >> n;
		for ( i = 0; i < n; i ++ )
			result.value[i] = i + 1;
		
		for ( i = 0; i < n; i ++ )
			cin >> vi.value[i];
		
		for ( i = 0; i < n; i ++ )
			if ( vi.value[i] != result.value[i] )
				break;
		if ( i == n ){
			cout << 0 << endl;
			continue;
		}
		top = 0;
		move( vi );
		for ( i = 0; i < top; i ++ )
			code[i] = i;
		qsort ( code, top, sizeof ( int ), cmp );
		for ( i = 0; i < n; i ++ )
			if ( moved[ code[0] ].value[i] != result.value[i] )
				break;
		if ( i == n ){
			cout << 1 << endl;
			continue;
		}
		for ( i = 0; i < top; i ++ )
			movef[i] = moved[ code[i] ];
		topf = top;
		
		top = 0;
		m = topf;
		for ( i = 0; i < m; i ++ )
			move( movef[i] );
		for ( i = 0; i < top; i ++ )
			code[i] = i;
		qsort ( code, top, sizeof ( int ), cmp );
		for ( i = 0; i < n; i ++ )
			if ( moved[ code[0] ].value[i] != result.value[i] )
				break;
		if ( i == n ){
			cout << 2 << endl;
			continue;
		}
		for ( i = 0; i < top; i ++ )
			movef[i] = moved[ code[i] ];
		topf = top;
		
		top = 0;
		move( result );
		for ( i = 0; i < top; i ++ )
			code[i] = i;
		qsort ( code, top, sizeof ( int ), cmp );
		m1 = topf;
		m2 = top;
		i = 0;
		j = 0;
		for ( i = 0; i < top; i ++ )
			moveb[i] = moved[ code[i] ];
		while ( i < m1 && j < m2 ){
			for ( k = 0; k < n; k ++ )
				if ( movef[i].value[k] != moveb[j].value[k] )
					break;
			if ( k == n )
				break;
			if ( vcmp( movef[i], moveb[j] ) )
				i ++;
			else
				j ++;
		}
		if ( i < m1 && j < m2 ){
			cout << 3 << endl;
			continue;
		}
		topb = top;
		
		top = 0;
		m = topb;
		for ( i = 0; i < m; i ++ )
			move( moveb[i] );
		qsort ( code, top, sizeof ( int ), cmp );
		for ( i = 0; i < top; i ++ )
			moveb[i] = moved[ code[i] ];
		m1 = topf;
		m2 = top;
		i = 0;
		j = 0;
		while ( i < m1 && j < m2 ){
			for ( k = 0; k < n; k ++ )
				if ( movef[i].value[k] != moveb[j].value[k] )
					break;
			if ( k == n )
				break;
			if ( vcmp ( movef[i], moveb[j] ) )
				i ++;
			else
				j ++;
		}
		if ( i < m1 && j < m2 ){
			cout << 4 << endl;
			continue;
		}
		
		cout << "5 or more" << endl;
	}
	
	return 0;
}

void move ( struct vector ori ){
	int i, j, k, kk;
	int t;
	vector now;
	
	for ( i = 1; i < n; i ++ )
		for ( j = 0; j + i < n; j ++ )
			for ( k = 1; k + i + j <= n; k ++ ){
				t = 0;
				for ( kk = 0; kk < j; kk ++ )
					now.value[ t ++ ] = ori . value[kk];
				for ( kk = 0; kk < k; kk ++ )
					now.value[ t ++ ] = ori . value[ kk + j + i ];
				for ( kk = 0; kk < i; kk ++ )
					now.value[ t ++ ] = ori . value[ kk + j ];
				for ( kk = 0; kk < n - k - i - j; kk ++ )
					now.value[ t ++ ] = ori . value[ kk + k + i + j ];
				for ( kk = 0; kk < n; kk ++ )
					moved[ top ] . value[kk] = now.value[kk];
				top ++;
			}
}

int cmp ( const void * a, const void * b ){
	int i;
	
	for ( i = 0; i < n; i ++ )
		if ( moved[ * ( ( int * ) a ) ].value[i] != moved[ * ( ( int * ) b ) ].value[i] )
			return moved[ * ( ( int * ) a ) ].value[i] - moved[ * ( ( int * ) b ) ].value[i];
	
	return 1;
}


int vcmp ( struct vector a, struct vector b ){
	int i;
	
	for ( i = 0; i < n; i ++ )
		if ( a.value[i] != b.value[i] )
			return a.value[i] < b.value[i];
			
	return 1;
}