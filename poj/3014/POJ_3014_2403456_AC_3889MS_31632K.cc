#include<iostream>
#define M 1000000007
int a[4501][4501],i,j,n,m;
int f(int n,int m)
{
    if(m > n)return f( n , n );
    if(n==0||n==1||m==1) return 1;
    if(a[n][m]) return a[n][m];
    else
    {
        a[n][m] = f( n - m , m ) + f(n , m - 1 );
        if(a[n][m] > M) a[n][m] -= M;
        return a[n][m];
    }
}
int main()
{
    memset(a,sizeof(a),0); 
    while(scanf("%d%d",&m,&n)!=EOF)
        printf("%d\n", f( n, m ) );
    return 0;
}
