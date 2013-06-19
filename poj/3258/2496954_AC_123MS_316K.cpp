#include <cstdio>
#include <algorithm>
using namespace std;

int l, n, m, d[50010];

bool judge ( int mid )
{
    int i, pre, tot;
    pre = 0; tot = 0;
    for ( i = 0 ; i < n ; i++ )
    {
        if (d[i] - pre < mid) 
			tot ++;
        else  
			pre = d[i];
    }
    if (l - pre < mid)    
		tot ++;
    
    if ( tot <= m )
        return true;
    else
		return false;
}

void solve ()
{
    int i, mid, Min, Max, key;
    for ( i = 0; i < n; i++ )
    scanf ("%d", &d[i]);
    sort (d, d + n);
    if ( n == 0 ) 
	{
		printf ("%d\n", l); 
		return;
	}
    if (m == 0)
    {
        Max = d[0];
        for (i = 1; i < n; i ++)
        {
            if ( d[i]-d[i-1] > Max ) 
				Max = d[i] - d[i - 1];
        }
        if ( l-d[n-1] > Max )   
			Max = l - d[n - 1];
        printf ("%d\n", Max);
        return;
    }
    Max = l; Min = 0;
    key = 0;
    while (Min <= Max)
    {
        mid = (Max + Min) / 2;
        if (judge (mid))
        {
            key = mid;
            Min = mid + 1;
        }
        else
        {
            Max = mid - 1;
        }
    }
    printf ("%d\n", key);
}

int main ()
{
    while (EOF != scanf ("%d %d %d", &l, &n, &m))
    solve ();
    return 0;
}
