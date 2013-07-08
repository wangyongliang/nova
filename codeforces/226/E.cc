// http://www.csie.ntnu.edu.tw/~u91029/DynamicTree.html

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100100
vector<int> tree[maxn];
int parent[maxn];
int heavy[maxn];
int depth[maxn];

int size[maxn];
int root;

vector<int> chain[maxn];
int chain_id[maxn];
int chain_pos[maxn];
int chain_size;
void dfs(int v, int d) {
  size[v] = 1;
  heavy[v] = -1;
  depth[v] = d;
  for (int i = 0; i < tree[v].size(); i ++) {
    dfs(tree[v][i], d + 1);
    size[v] += size[tree[v][i]];
    if (heavy[v] == -1 || size[heavy[v]] < size[tree[v][i]]) {
      heavy[v] = tree[v][i];
    }
  }
}
int head(int id) {
  return chain[id][0];
}

int lca(int v, int u) {
  while (chain_id[v] != chain_id[u]) {
    if (depth[head(chain_id[v])] < depth[head(chain_id[u])])
      u = parent[head(chain_id[u])];
    else
      v = parent[head(chain_id[v])];
  }
  return depth[u] < depth[v]? u: v;
}

class Segment{
public:
  Segment(int L, int R) {
    left = right = NULL;
    count = R - L + 1;
    if (L < R) {
      int M = (L + R) >> 1;
      left = new Segment(L, M);
      right = new Segment(M + 1, R);
    }
  }
  Segment(): left(NULL), right(NULL), count(0) {}
  int sum(int l, int r, int L, int R) {
    if (l <= L && r >= R)
      return count;
    int M = (L + R) >> 1;
    int result = 0;
    if (l <= M)
      result += left->sum(l, r, L, M);
    if (r > M)
      result += right->sum(l, r, M + 1, R);
  }

  int find(int pos, int L, int R) {
    if (L == R) {
      return L;
    } else {
      if (this->left->count <= pos)
        return this->left->find(pos, L, (L + R) >> 1);
      else
        return this->left->find(pos - this->left->count, ((L + R) >> 1) + 1, R);
    }
  }
  Segment* clone(int pos, int delta, int L, int R) {
    Segment* result = new Segment();
    result = memcpy(result, this, sizeof(Segment));
    result->count = this->count + delta;
    if (L == R) {
      return result;
    } else {
      int M = (L + R) >> 1;
      if (pos <= M) {
        result->left = this->left->clone(pos, delta, L, M);
      }
      if (pos > M) {
        resul->right = this->right->clone(pos, delta, M + 1, R);
      }
      return result;
    }
  }
  Segment* left, right;
  int count;
};

vector<pair<int, Segment*> >snapshots[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    chain_id[i] = heavy[i] = -1;
  }
  int x;
  for (int i = 0; i < n; i ++) {
    scanf("%d", &x); x--;
    parent[i] = x;
    if (x == 0) {
      root = i;
    } else {
      tree[x].push_back(i);
    }
  }
  dfs(root, 0);
  chain_size = 0;
  for (int i = 0; i < n; i ++) {
    if (chain_id[i] == -1) {
      for (int k = i; k != -1; k = heavy[k]) {
        chain_id[k] = chain_size;
        chain[chain_id[k]].push_back(k);
        chain_pos[k] = chain[chain_size].size() - 1;
      }
      chain_id ++;
    }
  }

  for (int i = 0; i < chain_id.size(); i ++) {
    snapshots[i].push_back(make_pair(0, new Segment(0, chain[i].size())));
  }

  int m;
  scanf("%d", &m);
  int a, b, k, y, type;
  for (int i = 1; i <= m; i ++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &a);
      a --;
      int id = chain_id[a];
      Segment* last = snapshots[id][snapshots[id].size() - 1];
      snapshots[id].push_back(make_pair(i,
        last->clone(chain_pos[a], -1, 0, chain[id].size() - 1)));
    } else {
      scanf("%d%d%d%d", &a, &b, &k, &y);
      a--, b--;
      int c = lca(a, b);
      if (a != c) {
        while(chain_id[a] != chain_id[c]) {

        }
      }
    }
  }

  return 0;
}