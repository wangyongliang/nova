#include <algorithm>
#include <cstdio>
using namespace std;

#define maxn 100010
char A[maxn];
char B[maxn];
bool C[maxn] = {0};
struct Node{
  int sum_;
  int val_;
}a[maxn * 4];
int n, q;

//  Build a segment tree
void build(int cur, int min, int max) {
  if (min == max) {
    a[cur].val_ = a[cur].sum_ = C[min];
  } else {
    a[cur].val_ = -1;
    int mid = (min + max) >> 1;
    build(cur * 2, min, mid);
    build(cur * 2 + 1, mid + 1, max);
    a[cur].sum_ = a[cur * 2].sum_ + a[cur * 2 + 1].sum_;
  }
}

// Update all the value between (x, y) to val
void update(int cur, int min, int max, int x, int y, int val) {
  if (x <= min && y >= max) {  // lazy update
    a[cur].sum_ = val * (max - min + 1);
    a[cur].val_ = val;
  } else {
    int mid = (min + max) >> 1;
    if (a[cur].val_ != -1) {  //
      update(cur * 2, min, mid, min , max, a[cur].val_);
      update(cur * 2 + 1, mid + 1, max, min, max, a[cur].val_);
      a[cur].val_ = -1;
    }
    if (x <= mid)
      update(cur * 2, min, mid, x, y, val);
    if (y > mid)
      update(cur * 2 + 1, mid + 1, max, x, y, val);
    a[cur].sum_ = a[cur * 2].sum_ + a[cur * 2 + 1].sum_;
  }
}

// Get the i-th bits
int Get(int cur, int min, int max, int x) {
  if (min == max)
    return a[cur].val_;
  else {
    if (a[cur].val_!= -1)
      return a[cur].val_;
    int mid = (min + max) >> 1;
    if (x <= mid)
      return Get(cur * 2, min, mid, x);
    else
      return Get(cur * 2 + 1, mid + 1, max, x);
  }
}

int sum(int cur, int min, int max, int x, int y) {
  if (x <= min && y >= max)
    return a[cur].sum_;
  int mid = (min + max) >> 1;
  if (a[cur].val_ != -1) {
    update(cur * 2, min, mid, min, max, a[cur].val_);
    update(cur * 2 + 1, mid + 1, max, min, max, a[cur].val_);
    a[cur].val_ = -1;
  }
  int result = 0;
  if (x <= mid)
    result += sum(cur * 2, min, mid, x, y);
  if (y > mid)
    result += sum(cur * 2 + 1, mid + 1, max, x, y);
  return result;
}

// find the first position which is 1
int first_one(int min, int max) {
  int mid;
  int start = min;
  while (min < max) {
    mid = (min + max)>>1;
    if (sum(1, 0, n, start, mid) > 0)
      max = mid;
    else min = mid + 1;
  }
  return min;
}

//  find the first zero by binary search
int first_zero(int min, int max) {
  int mid;
  int start = min;
  while (min < max) {
    mid = (min + max) >> 1;
    if (sum(1, 0, n, start, mid) == mid - start + 1)
      min = mid + 1;
    else
      max = mid;
  }
  return min;
}

int main() {
  // freopen("data.txt", "r", stdin);
  scanf("%d%d", &n, &q);
  scanf("%s", A);
  reverse(A, A + n);
  scanf("%s", B);
  reverse(B, B + n);
  int bit = 0;

  for (int i = 0; i < n; i ++) {
    bit += A[i] + B[i] - '0' * 2;
    C[i] =  bit % 2;
    bit /= 2;
  }
  C[n] = bit;

  build(1, 0, n);

  char buffer[100];
  int x;
  while (q--) {
    scanf("%s", buffer);
    if (buffer[0] == 's') { //  set a
      scanf("%d%d", &x, &bit);

      if (buffer[4] == 'a') {
        if (A[x] - '0' ==  bit) bit = -1;
        else A[x] = '0' + bit;
      } else {
        if (B[x] - '0' ==  bit) bit = -1;
        else B[x] = '0' + bit;
      }

      if (bit == 0) {  // minus one
        if (Get(1, 0, n, x) == 1) { //  from 1 -> 0
          update(1, 0, n, x, x, 0);
        } else {
          int next = first_one(x, n);
          // cout << "next: " << next << endl;
          update(1, 0, n, x, next - 1, 1);
          update(1, 0, n, next, next, 0);
        }
      } else if (bit == 1) { //  add one
        if (Get(1, 0, n, x) == 0) { //  from 0 -> 1
          update(1, 0, n, x, x, 1);
        } else {  // shift bits
          int next = first_zero(x, n);
          update(1, 0, n, x, next - 1, 0);
          update(1, 0, n, next, next, 1);
        }
      }
    } else {
      scanf("%d", &x);
      printf("%d", Get(1, 0, n, x));
    }
  }
  printf("\n");
  return 0;
}
