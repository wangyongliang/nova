#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 210000

int top[MAX_SIZE], tmp[MAX_SIZE];
void suffix_array( int *sa, int *rank, char *str, int len)
{
	int i,j,n1;
	len ++;
	n1=(len<256?256:len);
	memset( top, 0, n1*sizeof(int) );
	for(i=0;i<len ;i++)  top[ rank[i]= str[i]&0xff ]++;
	for(i=1;i<n1;i++)  top[ i ] += top[ i-1 ];
	for(i=0;i<len ;i++)  sa[ --top[rank[i]] ]=i;
	for( int jump=1; jump<=len; jump<<=1 )
	{
		for( i=0; i<len; i++ )
		{
			j=sa[i]-jump; if( j<0 ) j+=len;
			tmp[ top[rank[j]]++ ]=j;
		}
		sa[  tmp[ top[0]=0 ]  ] =  j=0  ;
		for( i=1; i<len; i++ )
		{
			if( rank[ tmp[i] ]!=rank[ tmp[i-1] ] ||
				rank[ tmp[i]+jump ]!=rank[ tmp[i-1]+jump ] ) top[++j]=i;
			sa[ tmp[i] ]=j;
		}
		memcpy( rank, sa , len*sizeof(int) );
		memcpy( sa  , tmp, len*sizeof(int) );
		if( j>=len-1 ) break;
	}
	for (i=0; i<len; i++) { sa[i]=sa[i+1]; rank[i]--; }
	return ;
}


int h[MAX_SIZE];
void make_LCP( int* LCP, int *sa, int *rank, char *str, int len )
{
	memset (h, -1, sizeof(h));
	for (int i=0; i<len; i++) {
		if (rank[i]==0) { h[i]=0; LCP[0]=0; continue; }
		int p;
		if (i==0||h[i-1]<=1) p=0; else p=h[i-1]-1;
		for (int a=i, b=sa[rank[i]-1]; ; p++) 
			if ( a+p>=len || b+p>=len || str[a+p] != str[b+p] ) { h[i]=p; break; }
			LCP [rank[i]] = h[i];
	}
	return ;
}

char str[MAX_SIZE];
int sa[MAX_SIZE];
int rank[MAX_SIZE];
int lcp[MAX_SIZE];
int len;
int k;
#define LUCKY 3
typedef long long lld;
typedef struct { lld val, n; } unit;
unit stack[MAX_SIZE];
void work()
{
	int mid, i;
	scanf ("%s", str);
	mid = len = strlen(str);
	str[len++] = LUCKY;
	scanf ("%s", str+len);
	len = strlen(str);

	suffix_array( sa, rank, str, len );
	make_LCP( lcp, sa, rank, str, len );

	int sp = 0;
	lld ans = 0, sum = 0;
	const lld inf = 2000000000;
	for (i=0; i<len; i++) {
		unit buf; buf.val = lcp[i]-k+1; buf.n = 0;
		if (buf.val<0) buf.val=0;
		while ( sp!=0 && stack[sp-1].val>=buf.val ) {
			sum -= stack[sp-1].val * (stack[sp-1].n);
			buf.n += stack[sp-1].n;
			sp--; 
		}
		stack[sp++] = buf;
		sum += buf.val*buf.n;
		if (sa[i]<mid) {	
			ans += sum;
		} else {
			stack[sp].val = inf; stack[sp++].n=1; sum += inf;
		}
	}

	lcp[len] = 0; sp=0; sum=0;
	for (i=len-1; i>=0; i--) {
		unit buf; buf.val = lcp[i+1]-k+1; buf.n = 0;
		if (buf.val<0) buf.val=0;
		while ( sp!=0 && stack[sp-1].val>=buf.val ) {
			sum -= stack[sp-1].val * (stack[sp-1].n);
			buf.n += stack[sp-1].n;
			sp--; 
		}
		stack[sp++] = buf;
		sum += buf.val*buf.n;
		if (sa[i]<mid) {	
			ans += sum;
		} else {
			stack[sp].val = inf; stack[sp++].n=1; sum += inf;
		}
	}
	printf ("%I64d\n", ans);
	return ;
}

int main ()
{
	while (scanf ("%d", &k)!=EOF && k!=0) work();
	return 0;
} 


