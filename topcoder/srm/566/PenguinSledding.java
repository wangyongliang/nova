// BEGIN CUT HERE

// END CUT HERE
import java.util.*;
public class PenguinSledding {
    public long countDesigns(int numCheckpoints, int[] checkpoint1, int[] checkpoint2) {
        long res = 0;
        return res;
    }

// BEGIN CUT HERE
    public static void main(String[] args) {
        try {
            eq(0,(new PenguinSledding()).countDesigns(2, new int[] {1}, new int[] {2}),2L);
            eq(1,(new PenguinSledding()).countDesigns(4, new int[] {1,2,3}, new int[] {2,3,4}),6L);
            eq(2,(new PenguinSledding()).countDesigns(6, new int[] {1,3,6}, new int[] {2,4,4}),5L);
            eq(3,(new PenguinSledding()).countDesigns(50, new int[] {40, 40, 40, 40, 40, 40, 40, 40,
                40, 40, 40, 40, 50, 40, 40, 40,
                23, 4, 24, 40, 22, 40, 8, 40, 40,
                40, 34, 21, 40, 40, 38, 40, 40,
                40, 40, 40, 28, 40, 40, 40, 40,
                46, 13, 40, 40, 40, 47, 40, 40}, new int[] {45, 42, 20, 48, 12, 32, 25, 10,
                26, 39, 16, 2, 19, 43, 37, 17,
                19, 19, 19, 18, 19, 27, 19, 29,
                11, 36, 19, 19, 1, 41, 19, 35,
                14, 33, 49, 3, 19, 7, 5, 19, 31,
                19, 19, 6, 9, 15, 19, 44, 30}),68719493118L);
            eq(4,(new PenguinSledding()).countDesigns(36, new int[] {13, 24, 24, 20, 31, 16, 10, 36, 34, 32,
                28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19,
                21, 8, 1, 26, 27, 25, 15, 22, 30, 30,
                6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18,
                13, 14, 17, 35, 3}, new int[] {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
                2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
                4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
                21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
                8, 36, 26, 23}),162L);
        } catch( Exception exx) {
            System.err.println(exx);
            exx.printStackTrace(System.err);
        }
    }
    private static void eq( int n, int a, int b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected "+b+", received "+a+".");
    }
    private static void eq( int n, char a, char b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected '"+b+"', received '"+a+"'.");
    }
    private static void eq( int n, long a, long b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected \""+b+"L, received "+a+"L.");
    }
    private static void eq( int n, boolean a, boolean b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected "+b+", received "+a+".");
    }
    private static void eq( int n, String a, String b ) {
        if ( a != null && a.equals(b) )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
    }
    private static void eq( int n, int[] a, int[] b ) {
        if ( a.length != b.length ) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++)
            if ( a[i] != b[i] ) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void eq( int n, long[] a, long[] b ) {
        if ( a.length != b.length ) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++ )
            if ( a[i] != b[i] ) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void eq( int n, String[] a, String[] b ) {
        if ( a.length != b.length) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++ )
            if( !a[i].equals( b[i])) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void print( int a ) {
        System.err.print(a+" ");
    }
    private static void print( long a ) {
        System.err.print(a+"L ");
    }
    private static void print( String s ) {
        System.err.print("\""+s+"\" ");
    }
    private static void print( int[] rs ) {
        if ( rs == null) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print(rs[i]);
            if ( i != rs.length-1 )
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void print( long[] rs) {
        if ( rs == null ) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print(rs[i]);
            if ( i != rs.length-1 )
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void print( String[] rs ) {
        if ( rs == null ) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print( "\""+rs[i]+"\"" );
            if( i != rs.length-1)
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void nl() {
        System.err.println();
    }
// END CUT HERE
}
