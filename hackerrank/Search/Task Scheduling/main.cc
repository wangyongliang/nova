// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
#include <iostream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define maxn 101000

struct node {
  int min;
  int val;
  bool flag;
}a[maxn*4];
void build(int x,int min,int max) {
  a[x].min = -min;
  a[x].val = 0;
  a[x].flag = false;
  if (min < max) {
    int mid = (min + max) /2;
    build (x*2,min,mid);
    build (x*2 + 1, mid + 1, max);
  }
}

void insert(int x,int min,int max,int val,int minx,int maxx) {
  if (minx <= min && maxx >= max) {
    a[x].flag = true;
    a[x].val += val;
    a[x].min += val;
  } else {
    int mid = (min + max) >>1;
    if (a[x].flag) {
      insert(x*2,min,mid,a[x].val,min,max);
      insert(x*2 + 1, mid + 1, max, a[x].val,min,max);
      a[x].flag = false;
      a[x].val = 0;

    }
    if (minx <= mid) insert (x*2,min,mid,val,minx,maxx);
    if (maxx > mid) insert(x*2 + 1, mid + 1,max, val ,minx, maxx);
    a[x].min  = a[x*2].min > a[x*2 + 1].min ? a[x*2].min : a[x*2 + 1].min;
  }
}

int main() {
  int t;
  build(1,1,maxn);
  scanf("%d",&t);
  int D,M;
  int ans = 0;
  for (int i = 0; i < t; i ++ ) {
    scanf("%d%d",&D,&M);
    insert(1,1,maxn,M,D,maxn);
    ans = a[1].min;
    if (ans < 0) ans = 0;
    cout << ans << endl;
  }
  return 0;
}