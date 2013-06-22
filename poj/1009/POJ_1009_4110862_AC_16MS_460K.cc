#include <iostream>
#include <math.h>
using namespace std;
typedef int RLE[2];
int w, n, ct, t;
RLE r[2000];
RLE cur, pos;
bool Move(RLE a, RLE b, int offset) {
  if ( a[0] < 0 || a[0] >= n ) return false;
  b[0] = a[0]; b[1] = a[1] + offset;
  while ( b[1] >= r[b[0]][1] && b[0] < n ) {
    b[1] -= r[b[0]][1];
    b[0]++;
  }
  if ( b[0] >= n ) return false;
  while ( b[1] < 0 && b[0] >= 0 ) {
    b[0]--;
    b[1] += r[b[0]][1];
  }
  if ( b[0] < 0 ) return false;
  return true;
}
void Advance() {
  int temp = r[pos[0]][1] - pos[1] - w - 1;
  if ( pos[1] > w && temp > 0 ) {
    cur[1] += temp;
    ct += temp;
    pos[1] += temp;
  }
  temp = w - 2 - ct % w;
  int temp2 = r[pos[0]][1] - pos[1] - 2;
  if ( pos[1] == 0 || pos[1] == 1 || ct % w == 0 ) temp2 = 0;
  int temp3, temp4;
  RLE trle;
  if ( !Move(pos, trle, -w - 2) ) temp3 = w;
  else temp3 = r[trle[0]][1] - trle[1] - 3;
  if ( !Move(pos, trle, w - 2) ) temp4 = w;
  else temp4 = r[trle[0]][1] - trle[1] - 3;
  temp = (temp < temp2) ? temp : temp2;
  temp = (temp < temp3) ? temp : temp3;
  temp = (temp < temp4) ? temp : temp4;
  if ( temp > 0 ) {
    cur[1] += temp;
    ct += temp;
    pos[1] += temp;
  }
  int hehe = 0;
  Move(pos, trle, -w - 1);
  if ( ct >= w && ct % w > 0 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, -w);
  if ( ct >= w ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, -w + 1);
  if ( ct >= w && ct % w != w - 1 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, -1);
  if ( ct % w > 0 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, 1);
  if ( ct % w != w - 1 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, w - 1);
  if ( ct < t - w && ct % w > 0 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, w);
  if ( ct < t - w ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  Move(pos, trle, w + 1);
  if ( ct < t - w && ct % w != w - 1 ) {
    temp = abs(r[trle[0]][0] - r[pos[0]][0]);
    if ( temp > hehe ) hehe = temp;
  }
  if ( cur[0] == -1 ) {
    cur[0] = hehe;
    cur[1] = 1;
  } else if ( hehe == cur[0] ) cur[1]++;
  else {
    cout << cur[0] << ' ' << cur[1] << endl;
    cur[0] = hehe;
    cur[1] = 1;
  }
  pos[1]++; ct++;
  if ( pos[1] == r[pos[0]][1] ) {
    pos[0]++;
    pos[1] = 0;
  }
}
void Output() {
  cur[0] = -1; cur[1] = -1;
  pos[0] = 0; pos[1] = 0;
  while ( true ) {
    if ( pos[0] == n ) break;
    Advance();
  }
  cout << cur[0] << ' ' << cur[1] << endl;
}
int main() {
  cin >> w;
  while ( w > 0 ) {
    cout << w << endl;
    n = 0;
    cin >> r[n][0] >> r[n][1];
    t = r[n][1]; ct = 0;
    while ( r[n][1] > 0 ) {
      n++;
      cin >> r[n][0] >> r[n][1];
      t += r[n][1];
    }
    Output();
    cout << "0 0" << endl;
    cin >> w;
  }
  cout << w << endl;

  return 0;
}