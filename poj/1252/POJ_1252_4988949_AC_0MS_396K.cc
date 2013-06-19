#include <iostream>
using namespace std;

int ret[500];
int list[500];

main(){
	int t;
	int i;
	int total;
	int mx;
	int beg, end;
	int a[10];
	int now;
	
	scanf ( "%d", &t );
	while ( t -- ){
		for ( i = 0; i < 6; i ++ )
			scanf ( "%d", a + i );
		memset ( ret, 0, sizeof ( ret ) );
		list[0] = 0;
		beg = 0;
		end = 1;
		while ( beg < end ){
			now = list[beg];
			for ( i = 0; i < 6; i ++ ){
				if ( now > a[i] )
					if ( ret[ now - a[i] ] == 0 ){
						ret[ now - a[i] ] = ret[ now ] + 1;
						list[ end ++ ] = now - a[i];
					}
				if ( now + a[i] <= 400 )
					if ( ret[ now + a[i] ] == 0 ){
						ret[ now + a[i] ] = ret[ now ] + 1;
						list[ end ++ ] = now + a[i];
					}
			}
			beg ++;
		}
		
		total = 0;
		mx = 0;
		for ( i = 1; i <= 100; i ++ ){
			total += ret[i];
			if ( ret[i] > mx )
				mx = ret[i];
		}
		
		printf ( "%d.", total / 100 );
		if ( total % 100 == total % 10 )
			printf ( "0" );
		printf ( "%d %d\n", total % 100, mx );
	}
	
	return 0;
}
