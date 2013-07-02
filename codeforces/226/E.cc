// http://www.csie.ntnu.edu.tw/~u91029/DynamicTree.html

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Segment {
public:
  Segment(int LEFT, int RIGHT) {
    count = RIGHT - LEFT + 1;
    if (LEFT == RIGHT) {
      left == NULL;
      right == NULL;
    } else {
      int MID = (LEFT + RIGHT) >> 1;
      left = new Segment(LEFT, MID);
      right = new Segment(MID + 1, RIGHT);
    }
  }
  Segment():left(NULL), right(NULL), count(0){}

  Segment *left
  Segment *right;
  int count;
  int sum(int left, int right, int LEFT, int RIGHT) {
    if (left <= LEFT && right >= RIGHT) {
      return count;
    }
    int MID = (LEFT + RIGHT) >> 1;
    return this->left->sum(left, right, LEFT, MID) + \
    this->right->sum(left, right, MID + 1, RIGHT);
  }
  Segment* clone(int pos, int delta, int LEFT, int RIGHT) {
    Segment* new_seg = new Segment();
    new_seg->count = this->count + delta;
    int MID = (LEFT + RIGHT) >> 1;
    if (pos <= MID) {
      new_seg->left = this->left->clone(pos, delta, LEFT, MID);
      new_seg->right = this->right;
    } else {
      new_seg->left = this->left;
      new_seg->right = this->right->clone(pos, delta, MID + 1, RIGHT);
    }
    return new_seg;
  }
};
#define MAXN 100100
bool visit[MAXN]={0};
// Store all paths
vector<int> paths[MAXN];
// Store different snapshot of segment tree
vector<pair<int, Segment*> > snapshots[MAXN];
// Store the path id for each vertex
int path_id[MAXN];
int path_num = 0;
vector<int> tree[MAXN];
int root;
int child[MAXN];
int heavy[MAXN];
// count the child and find out heavy edge
int find_heavy_edge(int v) {
  child[v] = 1;
  int max_child = -1;
  for (int i = 0; i < tree[v].size(); i ++) {
    child[v] += find_heavy_edge(tree[v][i]);
    if (max_child == -1 | child[max_child] < child[tree[v][i]]) {
      max_child = tree[v][i];
    }
  }
  if (max_child != -1) {
    heavy[v] = max_child;
  }
  return child[v];
}

// Split tree into sub-path
void split(int v) {
  if (!visit[v]) {
    int now = v;
    while (now != -1) {
      paths[path_num].push_back(v);
      path_id = [path_num];
      visit[now] = true;
      now = heavy[now];
    }
    path_num ++;
  }
  for (int i = 0; i < tree[v].size(); i ++) {
    split(tree[v][i]);
  }
}

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    heavy[i] = -1;
  }
  int x;
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &x);
    if (x == 0) {
      root = i;
    } else {
      tree[x].push_back(i);
    }
  }
  find_heavy_edge(root);
  split(root);
  for (int i = 0; i < path_num; i ++) {
    snapshots[i].push_back(make_pair(0, new Segment(0, paths[i].size())));
  }
  scanf("%d", &m);
  int type, a, b, k, y;
  while (m --) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &a);
    }
  }
  return 0;
}