#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

int n, k;
int start;
int arr[5000];
int list[10000];

main(){
	int beg, end, mid;
	int b, e;
	
	while ( scanf ( "%d %d", &n, &k ) != EOF ){
		beg = 1;
		end = n;
		while ( beg < end ){
			mid = ( beg + end + 1 ) / 2;
			memset( arr, 0, sizeof ( arr ) );
			arr[ mid ] = 1;
			list[0] = mid;
			b = 0;
			e = 1;
			while ( b < e ){
				if ( b == n - 1 ){
					b = e;
					break;
				}
				if ( list[b] - k < 1 )
					start = 1;
				else
					start = list[b] - k;
				for ( ; arr[ start ] != 0 && start <= n; start ++ );
				if ( start == n + 1 )
					break;
				arr[ start ] ++;
				list[ e ++ ] = start;
				list[ e ++ ] = list[b];
				b ++;
			}
			if ( b < e )
				end = mid - 1;
			else
				beg = mid;
		}
		printf( "%d\n", beg );
	}
	
	return 0;
}
