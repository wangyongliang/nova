#include <stdio.h>
int main ( void )
{
	int i , j , k , num ;
	int number ;

	scanf ( "%i" , &number ) ;

	for ( num = 1 ; num <= number ; ++num )
	    for ( i = 2 ;i * i * i<=num*num*num; ++i )
		for ( j = i ; i * i * i + j * j * j<=num*num*num; ++j )
		    for ( k = j ; i * i * i + j * j * j + k * k * k<=num*num*num; ++k )
			if ( num * num * num == i * i * i + j * j * j + k * k * k )
			    printf ( "Cube = %i, Triple = (%i,%i,%i)\n" , num , i , j , k ) ;
	

	return 0 ;
}