#include <stdio.h>

bool flag[1299710];
int prime[1000010],num;

void init()
{
	int i;
	prime[num++] = 2;
	for (i=3; i<1299710; i+=2)
	{
		if (!flag[i])
		{
			prime[num++] = i;

			for (int j=i+i; j<1299710; j+=i)
				flag[j] = true;
		}
	}
}

int main()
{
	int i,n,l,r,low,high,mid;
	init();
	while (scanf("%d",&n) && n)
	{
		if (n==2)
		{
			printf("0\n");
			continue;
		}
		if ((n&1) && !flag[n])
		{
			printf("0\n");
			continue;
		}
		low = 0, high = num-1;
		while (low<=high)
		{
			mid = (low+high) / 2;
			if (prime[mid]<n)
			{
				l = mid;
				low = mid + 1;
			}
			else if(prime[mid]>n)
			{
				high = mid - 1;
			}
		}
		low = 0, high = num-1;
		while (low<=high)
		{
			mid = (low+high) / 2;
			if (prime[mid]<n)
			{
				low = mid + 1;
			}
			else if (prime[mid]>n)
			{
				r = mid;
				high = mid - 1;
			}
		}
		printf("%d\n",prime[r]-prime[l]);

	}
	return 0;
}
