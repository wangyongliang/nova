#include<iostream>
using namespace std;
int main()
{
	int t,n,i,j,max;
	int a[30000],b[30000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset( b, 0, sizeof ( b ));
		max = 1;
		b[0] = 0;
		b[1] = a[0];
		for ( i = 1; i < n; i ++ )
		{
			for ( j = max; j > 0; j -- )
				if ( j % 2 )
				{
					if ( a[i] < b [j] )
						break;
				}
				else
					if ( a[i] > b [j] )
						break;
			j ++;
			if ( j > max )
			{
				max = j;
				b [j] = a[i];
			}

			if ( j % 2 )
			{
				if ( a[i] > b [j] )
					b [j] = a[i];
			}
			else  if ( a[i] < b [j] )
					b [j] = a[i];
		}

		cout << max << endl;
	}

	return 0;
}
