import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	public static void main ( String[] args ) throws Exception {
		Scanner cin = new Scanner( System.in );
		int n;
		BigInteger now;
		
		while ( cin.hasNext() ){
			n = cin.nextInt();
			now = BigInteger.ONE;
			while ( ( n -- ) != 0 ){
				System.out.println( now.add( BigInteger.ONE ).toString() );
				now = now.multiply( now.add( BigInteger.ONE ) );
			}
		}
	}
	
}
