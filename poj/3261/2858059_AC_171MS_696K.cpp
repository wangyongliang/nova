#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 20010;
int n,k,K;
int arr[maxn],rank[maxn],sa[maxn],height[maxn],h[maxn],trank[maxn],left[maxn],right[maxn],stack[maxn],top;

bool cmp(const int&a, const int &b)
{
	return arr[a] < arr[b];
}

bool cmp1(const int &a, const int &b)
{
	return (trank[a] < trank[b] || (trank[a] == trank[b] && trank[a+k] < trank[b+k]));
}

void suffix_array()
{
	int i,j;
	for (i=0; i<n; i++)
		sa[i] = i;
	sort(sa,sa+n,cmp);
	for (i=j=0; i<n; i++)
	{
		if (i && arr[sa[i-1]] < arr[sa[i]]) j++;
		rank[sa[i]] = j;
	}
	for (k=1; rank[sa[n-1]] < n-1; k<<=1)
	{
		for (j=0; j<n; j++)
			trank[j] = rank[j];
		sort(sa,sa+n,cmp1);
		for (i=j=0; i<n; i++)
		{
			if (i && cmp1(sa[i-1],sa[i])) j++;
			rank[sa[i]] = j;
		}
	}
	for (i=0; i<n; i++)
	{
		if (rank[i] == 0)
		{
			h[i] = 0;
			continue;
		}
		if (i==0 || h[i-1]<=1) k=0;
		else k = h[i-1] - 1;
		j = sa[rank[i]-1];
		for (; i+k<n && j+k<n; k++)
		{
			if (arr[i+k] != arr[j+k]) break;
		}
		h[i] = k;
	}
	for (i=0; i<n; i++)
	{
		height[rank[i]] = h[i];
	}
}

void solve()
{
	int ans = -1,i,l,r;
	top = 0;
	stack[top++] = -1;
	for (i=0; i<n; i++)
	{
		while (top>1 && height[stack[top-1]] >= height[i]) top--;
		left[i] = stack[top-1] + 1;
		stack[top++] = i;
	}
	top = 0;
	stack[top++] = n;
	for (i=n-1; i>=0; i--)
	{
		while (top>1 && height[stack[top-1]] >= height[i]) top--;
		right[i] = stack[top-1] - 1;
		stack[top++] = i;
	}
	for (i=1; i<n; i++)
	{
		if (height[i] > ans)
		{
			l = left[i];
			r = right[i];
			//if (l == i) l--;
			if ((r-l+2)>= K)
			{
				ans = height[i];
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int i;
/*
	freopen("E\\xyl\\in.txt","w",stdout);
	printf("%d %d\n",100,15);
	for (i=0; i<100; i++)
	{
		int j;
		if (i%5 == 0) j=i;
		else
			j = 1;
		printf("%d\n",j);
	}
	fflush(stdout);
*/
	//freopen("E:\\xyl\\patterns.7.in","r",stdin);
	//freopen("E:\\xyl\\out.txt","w",stdout);
	scanf("%d%d",&n,&K);
	for (i=0; i<n; i++)
		scanf("%d",&arr[i]);
	arr[n++] = -1;
	suffix_array();
	solve();
	return 0;
}
