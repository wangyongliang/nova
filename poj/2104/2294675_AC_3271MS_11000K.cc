#include <stdio.h>
#define MAX     100000
 
 
int     len;
struct  TNode {
        int     left , right;
        char    depth;
        TNode   *LeftChild , *RightChild;
        void    construct ( int , int , int );
        int     GetRank ();
}       Node [2 * MAX + 2];
 
 
int     SortArray [18] [MAX + 2];
 
 
int     Key , ls , rs;
void    TNode :: construct ( int l , int r , int dep )
{
        left = l; right = r; depth = dep;
        if ( left == right ) {
                scanf ( "%d" , &SortArray [dep] [l] );
                return;
        }
        int     mid = ( l + r ) >> 1;
        LeftChild = &Node [len ++];
        LeftChild->construct( l , mid , dep + 1 );
        RightChild = &Node [len ++];
        RightChild->construct( mid + 1 , right , dep + 1 );
 
 
        int     i = left , j = mid + 1 , k = left;
        while ( i <= mid && j <= r ) {
                if ( SortArray [dep + 1] [i] < SortArray [dep + 1] [j] )
                        SortArray [dep] [k ++] = SortArray [dep + 1] [i ++];
                        else
                        SortArray [dep] [k ++] = SortArray [dep + 1] [j ++];
        }
        while ( i <= mid ) SortArray [dep] [k ++] = SortArray [dep + 1] [i ++];
        while ( j <= right ) SortArray [dep] [k ++] = SortArray [dep + 1] [j ++];
}
 
 
int     TNode :: GetRank ()
{
        if ( ls <= left && right <= rs ) {
                if ( SortArray [depth] [left] >= Key ) return 0;
                if ( SortArray [depth] [right] < Key ) return right - left + 1;
                if ( SortArray [depth] [right] == Key ) return right - left;
                int     low = left , high = right , mid;
                while ( low + 1 < high ) {
                        mid = ( low + high ) >> 1;
                        if ( SortArray [depth] [mid] < Key ) low = mid;
                                else high = mid;
                }
                return low - left + 1;
        }
        int     ret = 0;
        if ( ls <= LeftChild->right ) ret += LeftChild->GetRank();
        if ( RightChild->left <= rs ) ret += RightChild->GetRank(); 
        return ret;
}
 
 
main ()
{
        int     N , Q , i;
        int     low , high , mid , Index;
        scanf ( "%d%d" , &N , &Q );
        len = 1; Node [0].construct( 0 , N - 1 , 0 );
        for ( i = 0; i < Q; i ++ ) {
                scanf ( "%d%d%d" , &ls , &rs , &Index );
                ls --; rs --;
                low = 0; high = N;
                while ( low + 1 < high ) {
                        mid = ( low + high ) >> 1;
                        Key = SortArray [0] [mid];
                        if ( Node [0].GetRank() >= Index ) high = mid;
                                else low = mid;
                }
                printf ( "%d\n" , SortArray [0] [low] );
        }
}
