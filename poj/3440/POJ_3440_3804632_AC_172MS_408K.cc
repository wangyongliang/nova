
#include <iostream>
#include <math.h>
using namespace std;

main (){
	double pi = acos( -1 );
	
	int ttt;
	double m, n, t, c;
	double e1, e2, e3, e4;
	double area;
	
	while ( scanf ( "%d", &ttt ) != EOF ){
		int tt = 0;
		while ( ttt -- ){
			if ( tt )
				printf ( "\n" );
			scanf ( "%lf%lf%lf%lf", &m, &n, &t, &c );
			c /= 2.0;
			e1 = 0.0;
			e2 = 0.0;
			e3 = 0.0;
			e4 = 0.0;
			
			area = ( t - c * 2.0 ) * ( t - c * 2.0 );
			e1 += area * m * n;
			
			area = c * ( t - c * 2.0 );
			e1 += 2 * m * area + 2 * n * area;
			e2 += ( m - 1 ) * n * 2 * area + m * ( n - 1 ) * 2 * area;
			
			area = c * c - pi * c * c / 4;
			e1 += 4 * area;
			e2 += ( m - 1 ) * 4 * area + ( n - 1 ) * 4 * area;
			e3 += ( m - 1 ) * ( n - 1 ) * 4 * area;
			
			area = pi * c * c / 4;
			e1 += 4 * area;
			e2 += ( m - 1 ) * 4 * area + ( n - 1 ) * 4 * area;
			e4 += ( m - 1 ) * ( n - 1 ) * 4 * area;
			
			area = ( t * n ) * ( t * m );
			
			if ( e1 <= 0.0 )	e1 = 0.0;
			if ( e2 <= 0.0 )	e2 = 0.0;
			if ( e3 <= 0.0 )	e3 = 0.0;
			if ( e4 <= 0.0 )	e4 = 0.0;
			
			printf ( "Case %d:\n", ++ tt );
			printf ( "Probability of covering 1 tile  = %.4lf%%\n", e1 / area * 100 );
			printf ( "Probability of covering 2 tiles = %.4lf%%\n", e2 / area * 100 );
			printf ( "Probability of covering 3 tiles = %.4lf%%\n", e3 / area * 100 );
			printf ( "Probability of covering 4 tiles = %.4lf%%\n", e4 / area * 100 );
		}
	}
	
	return 0;
}

 
 