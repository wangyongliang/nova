/*
PROB: expand
LANG: C++
*/

#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

//FILE *Fin = fopen("expand.in","r");
//FILE *Fou = fopen("expand.out","w");
FILE *Fin = stdin;
FILE *Fou = stdout;

const int MaxN = 25000 + 100;

int n;
struct TRec
{
	int x1,y1,x2,y2; bool poss;
} R[MaxN];

void Init()
{
	fscanf(Fin,"%d",&n);
	int i;
	for (i=0; i<n; i++)
	{
		fscanf(Fin,"%d %d %d %d",&R[i].x1,&R[i].y1,&R[i].x2,&R[i].y2);
		R[i].poss = true;
	}
}

struct TSeg
{
	int x, l, r, id;
} s[MaxN+MaxN];
bool operator < (TSeg a, TSeg b)
{
	if (a.x<b.x) return true;
	if (a.x>b.x) return false;
	return a.l<b.l||a.l==b.l&&a.r<b.r;
}

void Work()
{
	int i,j,k,m;
	m = 0;
	for (i=0; i<n; i++)
	{
		s[m].x = R[i].x1, s[m].l = R[i].y1, s[m].r = R[i].y2, s[m].id = i; m++;
		s[m].x = R[i].x2, s[m].l = R[i].y1, s[m].r = R[i].y2, s[m].id = i; m++;
	}
	sort(s, s+m);
	for (i=0; i<m; i=j)
	{
		for (j=i+1; s[i].x==s[j].x; j++);
		int r = -1, l = 0x7FFFFFFF;
		for (k=i; k<j; k++)
		{
			if (s[k].l<=r) R[s[k].id].poss = false;
			if (s[k].r>r) r = s[k].r;
		}
		for (k=j-1; k>=i; k--)
		{
			if (s[k].r>=l) R[s[k].id].poss = false;
			if (s[k].l<l) l = s[k].l;
		}
	}
}

void Doit()
{
	int i;
	Work();
	for (i=0; i<n; i++) swap(R[i].x1, R[i].y1), swap(R[i].x2, R[i].y2);
	Work();
	int ans = 0;
	for (i=0; i<n; i++) if (R[i].poss) ans++;
	fprintf(Fou,"%d\n",ans);
}

int main()
{
	Init();
	Doit();
	return 0;
}

