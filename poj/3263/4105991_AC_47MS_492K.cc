#include<cstdio>

#define MAXN 500000
#define MAXR 2*MAXN

int N, I, H, R;
int bucket[MAXN], order[MAXR], pairs[MAXR][2];
int interval[MAXN];

void radix_sort()
{
	int r, i;
	for(r = 0; r < 2; ++r)
	{
		for(i = 0; i < N; ++i) bucket[i] = 0;
		for(i = 0; i < R; ++i) ++bucket[ pairs[i][r] ];
		for(i = 1; i < N; ++i) bucket[i] += bucket[i-1];
		for(i = N; i > 0; --i) bucket[i] = bucket[i-1];
		bucket[0] = 0;
		for(i = 0; i < R; ++i) order[ bucket[ pairs[i][r] ]++ ] = i;
	}
}

void trim_same()
{
	int r, i;
	radix_sort();
	r = 1;
	for(i = 1; i < R; ++i)
	{
		if(pairs[order[i]][0] == pairs[order[i-1]][0] &&
		   pairs[order[i]][1] == pairs[order[i-1]][1])
			continue;
		order[ r++ ] = order[ i ];
	}
	R = r;
}

int main()
{
	int i, a, b;
	scanf("%d %d %d %d", &N, &I, &H, &R);
	for(i = 0; i < R; ++i)
	{
		scanf( "%d %d", &a, &b);
		--a;
		--b;
		if(a<b) {
			pairs[i][0] = a;
			pairs[i][1] = b;
		} else {
			pairs[i][0] = b;
			pairs[i][1] = a;
		}
		order[i] = i;
	}
	trim_same();            //Each interval should be examined once
	for(i = 0; i < R; ++i)
	{
		a = pairs[ order[i] ][ 0 ];
		b = pairs[ order[i] ][ 1 ];
		--interval[a+1];
		++interval[ b ];
	}
	a = 0;
	for(i = 0; i < N; i++)
	{
		a += interval[ i ];
		printf("%d\n", H + a);
	}
	return 0;
}