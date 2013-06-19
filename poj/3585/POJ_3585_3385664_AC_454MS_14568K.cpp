#include <stdio.h>
#include <memory.h>
#include <limits.h>

#define min(a, b)  ( ((a)>(b))?(b):(a) )
 
typedef struct {
	int from, to, cap, delta, nxt;
}Edge;

Edge edges[400000];
int head[200000], ep;
int ans[200000], deg[200000];

void AddEdge( int a, int b, int cap ) {
	edges[ep].from = a; edges[ep].to=b; edges[ep].cap=cap; 
	edges[ep].delta=0; edges[ep].nxt=head[a]; head[a]=ep;
	ep++; deg[a]++;
	edges[ep].from = b; edges[ep].to=a; edges[ep].cap=cap; 
	edges[ep].delta=0; edges[ep].nxt=head[b]; head[b]=ep;
	ep++; deg[b]++;
}

int bfs( int eid ) {
	int v=(eid==-1)?0:edges[eid].to;
	int delta, p;
	if ( deg[v]==1 && eid!=-1 ) delta=INT_MAX;
	else {
		delta=0;
		for ( p=head[v]; p!=-1; p=edges[p].nxt ) {
			if ( eid!=-1 && edges[p].to==edges[eid].from ) continue;
			delta += bfs( p );
		}
	}
	if ( eid!=-1 ) {
		delta = min( delta, edges[eid].cap );
		edges[eid].delta = delta;
	}
	return delta;
}

void track( int v, int feid ) {
	int p;
	ans[v]=0;
	for ( p=head[v]; p!=-1; p=edges[p].nxt ) {
		ans[v] += edges[p].delta;
	}
	for ( p=head[v]; p!=-1; p=edges[p].nxt ) {
		int rp = p^0x1, t=ans[v]-edges[p].delta;
		if (rp==feid) continue;
		if (deg[v]==1) t=INT_MAX;
		edges[rp].delta = min( t, edges[rp].cap );
	}
	for ( p=head[v]; p!=-1; p=edges[p].nxt ) {
		if ( feid!=-1 && p==(feid^0x1) ) continue;
		track( edges[p].to, p );
	}
}

void work () {
	int n, i, res=0; 
	ep=0;
	scanf ("%d", &n);
	memset( head, -1, sizeof(int)*n );
	memset( deg, 0, sizeof(int)*n );
	for ( i=0; i<n-1; i++ ) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c) ;
		a--; b--;
		AddEdge(a, b, c);
	}

	bfs(-1);
	track(0, -1);

	for ( i=0; i<n; i++ ) {
		if ( res<ans[i] ) res=ans[i];
	}
	printf ("%d\n", res);
	return ;
}

int main () {
	int nc;
	scanf ("%d", &nc);
	while (nc--) {
		work();
	}
	return 0;
}
