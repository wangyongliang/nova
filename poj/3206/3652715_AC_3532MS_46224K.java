/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Bjtu1
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main ( String argv[] ){
        Scanner cin = new Scanner ( System.in );
        BigInteger ans[][] = new BigInteger[512][512];
        for ( int n = 0; n < 512; n ++ )
            for ( int k = 0; k < 512; k ++ )
                ans[n][k] = BigInteger.ZERO;
        ans[0][0] = BigInteger.ONE;
	for ( int n=0; n<=500; n++ ) {
		for ( int k=0; k<=n; k++ ) {
			ans[n+1][k] = ans[ n + 1 ][k].add( ans[n][k].multiply( BigInteger.valueOf( k ) ) );
			ans[n+1][k+1] = ans[n+1][k+1].add( ans[n][k].multiply( BigInteger.valueOf( n - k + 1 ) ) );
		}
	}
        while ( cin.hasNext() ){
            int a = cin.nextInt();
            int b = cin.nextInt();
            if ( a + b == 0 )
                break;
            System.out.println( ans[a][b] );
        }
        
    }
}

