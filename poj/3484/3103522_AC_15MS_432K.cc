#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef __int64 uint;

typedef struct Node
{
	int x,k,z;
}Node;

Node arr[1000001];
int n;
uint high,low;

void work()
{
	int k=0,p,i;
	int mid, ans=0;
	while (low<=high)
	{
		k=0;
		mid = uint(uint(low)+uint(high)) / 2;
		for (int j=0; j<n; j++)
		{
			if (mid>=arr[j].x)
			{
				p = (mid-arr[j].x) / arr[j].z;
				if (p<=arr[j].k)
				k += p + 1;
				else
					k += arr[j].k + 1;
			}
		}
		if (k%2)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	if (ans==0)
	{
		puts("no corruption");
	}
	else
	{
		for (i=k=0; i<n; i++)
		{
			if (ans>=arr[i].x && ans<=arr[i].x+arr[i].z * arr[i].k && (ans-arr[i].x) % arr[i].z==0) k++;
		}
		printf("%d %d\n",ans,k);
	}
}

int main()
{
	int x,y,z;
	char ch;
	while (1)
	{
		n = 0;
		high = -1,low=0x7FFFFFFF;
		while (1)
		{
			ch = getchar();
			if (ch==EOF)
			{
				if (n>0)
					work();
				return 0;
			}
			else if (ch=='\n')
			{
				if (n>0)
				work();
				break;
			}
			/*
			while ((ch=getchar()) && !(ch>='0' && ch<='9'));
			if (ch==EOF)
			{
				if (n>0)
				{
					work();
				}
				return 0;
			}
			else if (ch=='\n')
			{
				work();
				break;
			}
			*/
			x = ch-'0';
			while ((ch=getchar()) && ch>='0' && ch<='9')
				x *=10, x+= ch-'0';
			while ((ch=getchar()) && !(ch>='0' && ch<='9'));
			y = ch-'0';
			while ((ch=getchar()) && ch>='0' && ch<='9')
				y*=10, y+=ch-'0';
			while ((ch=getchar()) && !(ch>='0' && ch<='9'));
			z = ch-'0';
			while ((ch=getchar()) && ch>='0' && ch<='9')
				z*=10,z+=ch-'0';
			arr[n].x = x;
			arr[n].z = z;
			arr[n++].k = (y-x)/z;
			if (low>x) low = x;
			if (high<y) high = y;
		}
	}
	return 0;
}
