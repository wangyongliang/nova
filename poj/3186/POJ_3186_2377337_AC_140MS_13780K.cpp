#include <stdio.h>
#include <stdlib.h>
#define MAX 2001
int f[2001][2001]={0};
int main()
{
    
    int n ; 
    int a[MAX];
    scanf("%d",&n) ;
    int i; 
    for ( i = 1 ; i <= n ; i ++ )
        scanf("%d",&a[ i ]);    
    int j ; 
    for ( i = n; i  >= 1 ; i -- )
        for  ( j = i ; j <= n ; j ++ )
        {
            f[i][j]= f[i+1][j]+a[i]*(n-j+i);
            if ( f[ i ] [ j - 1 ] + a[ j ] * ( n - j + i ) > f[ i ][ j ] )
                f[i][j] = f[ i ] [ j - 1 ] + a[ j ] * ( n - j + i ) ;
        }
    printf("%d\n",f [ 1 ] [ n ]);
    return 0;
}