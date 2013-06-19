#include <iostream>
using namespace std;

long long step[50][3];
int peg[50][3];

char move[6][5];

main(){
	int nowpeg, leftpeg, bigpeg, endpeg;
	int i, j;
	long long astep;
	int nextk;
	int n;
	
	while ( cin >> n ){
		for ( i = 0; i < 6; i ++ )
			cin >> move[i];
		
		memset ( step, 0, sizeof ( step ) );
		memset ( peg, 0, sizeof ( peg ) );
		
		for ( i = 1; i <= 1; i ++ )
			for ( j = 0; j < 3; j ++ ){
				astep = 0;
				nextk = 0;

				while( move[nextk][0] != 'A' + j ){
					nextk ++;
					if ( nextk == 6 )
						nextk = 0;
				}
				endpeg = move[nextk][1] - 'A';
				astep ++;
					
				step[i][j] = astep;
				peg[i][j] = endpeg;
			}
		
		for ( i = 2; i <= n; i ++ )
			for ( j = 0; j < 3; j ++ ){
				astep = 0;
				astep = step[ i - 1 ][j];
				nowpeg = j;
				bigpeg = j;
				while( true ){
					leftpeg = 3 - bigpeg - peg[ i - 1 ][ nowpeg ];
					astep ++;
					
					nowpeg = 3 - leftpeg - bigpeg;
					bigpeg = leftpeg;

					astep += step[ i - 1 ][ nowpeg ];
					if ( peg[ i - 1 ][ nowpeg ] == leftpeg )
						break;
				}
				step[i][j] = astep;
				peg[i][j] = bigpeg;
			}		
		cout << step[n][0] << endl;
	}
	
	return 0;
}

