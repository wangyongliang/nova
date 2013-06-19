#include <iostream>
#include <map>
using namespace std;

#define MAX 32768

int suffix[ MAX * 2 ];

int b[ MAX * 2 ];
int e[ MAX * 2 ];
int m[ MAX * 2 ];

void findbem( int, int, int );

int findboss( int, int );
int asksuffix( int, int &);
void addsuffix( int, int &);
void minussuffix( int, int &);

int record[MAX];
int sub[MAX];
map< int, int > seq;
pair< pair< int, int >, int > list[MAX];
pair< int, int > query[210];
pair< int, int > ret[210];

main (){
	findbem( 1, 1, MAX );

	int t;
	int n, q;
	int id, salary, height;
	
	int i, j;
	int ptr;
	int boss;
	
	int beg, end, mid;
	
	scanf ( "%d", &t );
	while ( t -- ){
		scanf ( "%d %d", &n, &q );
		for ( i = 0; i < n; i ++ ){
			scanf ( "%d %d %d", &id, &salary, &height );
			list[i] = make_pair( make_pair( height, salary ), id );
			record[i] = salary;
		}
		sort ( list, list + n );
		sort ( record, record + n );
		for ( i = 0; i < n; i ++ ){
			beg = 0;
			end = n - 1;
			while ( beg < end ){
				mid = ( beg + end ) / 2;
				if ( record[mid] == list[i].first.second )
					break;
				if ( record[mid] < list[i].first.second )
					beg = mid + 1;
				else
					end = mid;
			}
			mid = ( beg + end ) / 2;
			list[i].first.second = mid + 1;
		}
		
		seq.clear();
		for ( i = 0; i < n; i ++ )
			seq[ list[i].second ] = i;
		for ( i = 0; i < q; i ++ ){
			scanf ( "%d", &id );
			query[i] = make_pair( seq[id], i );
		}
		sort ( query, query + q );
		query[q] = make_pair( n, q );
		
//for ( i = 0; i < n; i ++ )	cout << list[i].first.second << " "; cout << endl;
		
		record[0] = 0;
		for ( i = 0; i < n; i ++ )
			record[ list[i].first.second ] = list[i].second;
		memset ( sub, 0, sizeof ( sub ) );
		memset ( suffix, 0, sizeof( suffix ) );
		for ( i = 0; i < n; i ++ )
			addsuffix( 1, list[i].first.second );

		ptr = 0;
		for ( i = 0; ptr < q; i ++ ){
			minussuffix( 1, list[i].first.second );
			salary = asksuffix( 1, list[i].first.second );
			boss = findboss( 1, salary + 1 );
//cout << salary << " " << boss << endl;
			sub[ boss ] += sub[ list[i].first.second ] + 1;
			while ( i == query[ ptr ].first ){
				ret[ query[ ptr ].second ].second = sub[ list[i].first.second ];
				ret[ query[ ptr ].second ].first = record[ boss ];
				ptr ++;
			}
		}
		
		for ( i = 0; i < q; i ++ )
			printf ( "%d %d\n", ret[i].first, ret[i].second );
	}
	
	return 0;
}

void findbem( int k, int beg, int end ){
	b[k] = beg;
	e[k] = end;
	m[k] = ( beg + end ) / 2;
	
	if ( beg == end )
		return;
	
	findbem( k * 2, beg, m[k] );
	findbem( k * 2 + 1, m[k] + 1, end );
}

void addsuffix( int k, int &a ){
	suffix[k] ++;
	if ( b[k] == e[k] )
		return;
	
	if ( m[k] < a )
		addsuffix( k * 2 + 1, a );
	else
		addsuffix( k * 2, a );
}

void minussuffix( int k, int &a ){
	suffix[k] --;
	if ( b[k] == e[k] )
		return;
	
	if ( m[k] < a )
		minussuffix( k * 2 + 1, a );
	else
		minussuffix( k * 2, a );
}


int asksuffix( int k, int &a ){
	if ( b[k] == e[k] )
		return suffix[k];
	
	if ( m[k] < a )
		return suffix[ k * 2 ] + asksuffix( k * 2 + 1, a );
	else
		return asksuffix( k * 2, a );
}

int findboss( int k, int a ){
	if ( b[k] == e[k] )
		return m[k];
	
	if ( a > suffix[ k * 2 ] )
		if ( a > suffix[ k * 2 ] + suffix[ k * 2 + 1 ] )
			return 0;
		else
			return findboss( k * 2 + 1, a - suffix[ k * 2 ] );
	else
		return findboss( k * 2, a );
}
