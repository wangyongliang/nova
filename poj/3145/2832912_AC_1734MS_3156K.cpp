#include <stdio.h>
#include <set>
#define SPEED 1000
#define INF 100000000

using namespace std;

int base[500001];
int index[40001];

int main( void )
{
	set<int> sou;
	set<int>::iterator it;
	char ch;
	int t, k, order, min, max, tmp, res, i, j, r = 0;
	while ( scanf( "%d", &t ) && t )
	{
		sou.clear();
		min = INF, max = -INF;
		printf( "Case %d:\n", ++r );
		for ( i = 0, order = 1; i < t; ++i )
		{
			scanf( " %c%d", &ch, &k );
			if ( ch == 'B' )
			{
				sou.insert( k );
				index[order] = k;
				base[k] = order++;
				if ( min > k ) min = k;
				if ( max < k ) max = k;
				continue;
			}
			if ( order == 1 )
			{
				puts( "-1" );
				continue;
			}
			if ( k == 1 )
			{
				puts( "1" );
				continue;
			}
			if ( k <= SPEED )
			{
				for ( j = order - 2, res = index[j + 1]; j >= 1; --j )
				{
					if ( index[j] % k < res % k )
					{
						res = index[j];
					}
					if ( res % k == 0 )
					{
						break;
					}
				}
				printf( "%d\n", base[res] );
				continue;
			}
			tmp = min - min % k + k; res = min;
			while ( tmp <= max )
			{
				it = sou.lower_bound( tmp );
				if ( *it < tmp + k )
				{
					if ( *it - tmp < res % k || ( *it - tmp == res % k && base[*it] > base[res] ) )
					{
						res = *it;
					}
					tmp += k;
				}
				else if ( it != sou.end() )
				{
					if ( *it % k < res % k || ( *it % k == res % k && base[*it] > base[res] ) )
					{
						res = *it;
					}
					tmp = *it - *it % k + k;
				}
				else
				{
					break;
				}
			}
			printf( "%d\n", base[res] );
		}
		putchar( '\n' );
	}
	return 0;
}
