// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int i;
    for (i = 1; i < a.size() && a[i] < a[0] + k; i ++);
    int j = 0;
    int res = 0;
    for (; i < a.size(); i ++) {
        for (; a[j] + k < a[i]; j ++);
        if (a[j] + k == a[i]) res ++;
    }
    cout << res << endl;
    return 0;
}