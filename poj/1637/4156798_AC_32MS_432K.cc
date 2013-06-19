#include <cstdio>
#include <memory>
#include <algorithm>
using namespace std;

const int Inf=0x7FFFFFFF;

#define VSIZE 300
#define ESIZE 3000
int ep, head[VSIZE], nVert;
struct Edge {
	int to, next, cap, flow;
} edges[ESIZE];

void InitGraph( int nv ) { nVert=nv; ep=0; memset(head, -1, sizeof(head)); }
void AddEdge( int a, int b, int c ) {
	edges[ep].to=b; edges[ep].cap=c; edges[ep].flow=0; edges[ep].next=head[a]; head[a]=ep++;
	edges[ep].to=a; edges[ep].cap=c; edges[ep].flow=c; edges[ep].next=head[b]; head[b]=ep++;
}

void AddDualEdge( int a, int b, int c ) {
	edges[ep].to=b; edges[ep].cap=c; edges[ep].flow=0; edges[ep].next=head[a]; head[a]=ep++;
	edges[ep].to=a; edges[ep].cap=c; edges[ep].flow=0; edges[ep].next=head[b]; head[b]=ep++;
}

int level[VSIZE], stack[VSIZE][3], sp; // v, edge_id.
int DFS(int src, int dest) {
#define PUSH(v, p, f) { stack[sp][0]=v; stack[sp][1]=p; stack[sp++][2]=f; }
	sp=0;
	PUSH(src, -1, head[src]);
	int ret=0;
	while ( sp>0 ) {
		int v=stack[sp-1][0];
		if (v==dest) {
			int mnf=Inf, earlyNode=-1;
			for ( int i=1; i<sp; i++ ) mnf=min(mnf, edges[stack[i][1]].cap-edges[stack[i][1]].flow);
			for ( int i=1; i<sp; i++ ) { 
				edges[stack[i][1]].flow += mnf; 
				if ( earlyNode==-1 && edges[stack[i][1]].flow==edges[stack[i][1]].cap ) earlyNode=i;
			}
			ret+=mnf;
			//printf ("Find flow: %d\n", mnf);
			sp=earlyNode;
		} else {
			for ( int &p=stack[sp-1][2]; p!=-1; p=edges[p].next ) {
				if ( level[edges[p].to]==level[v]+1 && edges[p].cap>edges[p].flow ) {
					PUSH(edges[p].to, p, head[edges[p].to]); goto NEXT;
				}
			}
			sp--;
			level[v]=-1;
		}
NEXT: 
		{;}
	}
	return ret;
#undef PUSH
}

int MaxFlow( int src, int dest ) {
	int queue[VSIZE], qp, delt, ans=0;
	bool inc=true;
#define PUSH(v, l) { if ( level[v]==-1 ) { queue[qp++]=v; level[v]=l; }  }
	while (inc) {
		inc=false;
		memset( level, -1, sizeof(int)*nVert );
		qp=0; PUSH(src,0);
		for ( int i=0; i<qp; i++ ) {
			bool f=false;		
			for ( int p=head[queue[i]]; p!=-1; p=edges[p].next ) {
				if (edges[p].flow<edges[p].cap) {
					PUSH( edges[p].to, level[queue[i]]+1 );
					if ( edges[p].to==dest ) { f=true; break; }
				}
			}
			if (f) break;
		}
		if ( level[dest]==-1 ) break;
		if ( (delt=DFS(src, dest)) != 0 ) inc=true;
		ans += delt;
	}
	return ans;
#undef PUSH
}

int n, m;
bool graph[256][256];
int deg[256], emp[1000][2], empp, edeg[256];
bool Eular() {
	int queue[256],qp=0,tot=0;
	bool been[256]={false};
	#define PUSH(x) { if (!been[x]) {been[x]=true; tot++; queue[qp++]=x;} }
	PUSH(1);
	for (int i=0; i<qp; i++) {
		int v=queue[i];
		for (int j=1; j<=n; j++) if (graph[v][j]) PUSH(j);
	}
	if (tot!=n) return false;
	InitGraph(n+5);
	int Src=0, Dest=n+1, fin=0, fout=0;
	for (int i=1; i<=n; i++) {
		if (deg[i]>0) AddEdge(i,Dest,deg[i]), fin+=deg[i];
		else if (deg[i]<0) AddEdge(Src,i,-deg[i]), fout+=-deg[i];
	}
	if (fin!=fout) return false;
	if (fin==0) {
		for (int i=1; i<=n; i++) if (edeg[i]%2!=0) {
			return false;
		}
		return true;
	}
	for (int i=0; i<empp; i++) {
		AddDualEdge(emp[i][0],emp[i][1],1);
	}
	int x=MaxFlow(Src,Dest);
	if (x==fin) return true;
	else return false;
}

int main () {
    int t;
    scanf("%d",&t);
    while (t--) {
		scanf("%d%d", &n, &m);
		memset(graph,0,sizeof(graph));
		memset(deg,0,sizeof(deg));
		memset(edeg,0,sizeof(edeg));
		empp=0;
		for (int i=0; i<m; i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			graph[a][b]=true;
			if (c==1) { deg[a]--; deg[b]++; }
			if (c==0) {
				graph[b][a]=true;
				emp[empp][0]=a; emp[empp++][1]=b;
				edeg[a]++; edeg[b]++;
			}
		}
		if (Eular()) printf ("possible\n");
		else printf ("impossible\n");
	}
    return 0;
}
