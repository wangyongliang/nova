#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 1100000
#define MAXQ 30000

struct qtype {
    int	    p1, p2, res, id;
    bool    operator < (const qtype & o)const {
	return p1 < o.p1;
    }
};
qtype	lis[MAXQ];

pair <int, int> lis1[MAXQ];

int	last[MAXQ], v[MAXN], n, q;

priority_queue <pair <int, int> >lim;

int	left[MAXQ], right[MAXQ];

pair <pair <int, int>, int> need[MAXQ];
int	needt;

int 
work (int len) {
    int	    i, i1, i2;
    if (len > q)
	return 0;
    while (!lim.empty ())
	lim.pop ();
    for (i = 0; i < q; i++) {
	left[i] = 0;
	right[i] = n;
	last[i] = 0;
    }
    for (i = 0; i < q; i++)
	if (lis[i].id < len) {
	    left[lis[i].res] >?= lis[i].p1;
	    right[lis[i].res] <?= lis[i].p2;
	}
    needt = 0;
    for (i = 0; i < q; i++)
	if (left[i] != 0) {
	    need[needt].first.first = right[i];
	    need[needt].first.second = left[i];
	    need[needt++].second = i;
	}
    sort (need, need + needt);
    for (i = 1, i1 = i2 = 0; i <= n; i++) {
	for (; (i1 < q) && (lis[i1].p1 == i); i1++)
	    if (lis[i1].id < len) {
		lim.push (pair < int, int >(lis[i1].res, lis[i1].p2));
	    }
	while ((!lim.empty ()) && (lim.top ().second < i))
	    lim.pop ();
	if (lim.empty ())
	    v[i] = 0;
	else
	    v[i] = lim.top ().first;
	last[v[i]] = i;
	for (; (i2 < needt) && (need[i2].first.first == i); i2++)
	    if (last[need[i2].second] < need[i2].first.second)
		return 0;
    }
    return 1;
}

int 
main ()
{
    int	    i, j, tot, ans, del;
    scanf ("%d%d", &n, &q);
    for (i = 0; i < q; i++) {
	scanf ("%d%d%d", &lis[i].p1, &lis[i].p2, &lis[i].res);
	lis[i].id = i;
	lis1[i].first = lis[i].res;
	lis1[i].second = i;
    }
    sort (lis1, lis1 + q);
    for (i = tot = 0; i < q; i++) {
	tot += ((i == 0) || (lis1[i].first != lis1[i - 1].first));
	lis[lis1[i].second].res = tot;
    }
    sort (lis, lis + q);
    for (del = 1 << 16, ans = 0; del; del /= 2)
	if (work (ans + del))
	    ans += del;
    printf ("%d\n", (ans < q) ? (ans + 1) : 0);
    return 0;
}
