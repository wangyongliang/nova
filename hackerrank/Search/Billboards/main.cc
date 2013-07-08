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

#define maxn  1000000
#define INF32 2147483647
#define INF64 9223372036854775807LL
long long sum[maxn]={0};
int m,now;
long long dp[maxn];

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a;
    a.push_back(0);
    sum[0] = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a.push_back(i);
        sum[i + 1] = sum[i] + x;
    }
    m = 0;
    deque<int> q;
    q.push_back(0);
    long long res = 0;
    for(int i = 1; i <=n; i ++) {
        if (i <= k) dp[i] = sum[i];
        else dp[i] = 0;
        while(q.size() > 0 && q.front() + k + 1 < i) q.pop_front();
        if (q.size() > 0) {
            int x = q.front();
            dp[i] = max(dp[i],dp[x] + sum[i] - sum[x + 1]);
        }
        res = max(res,dp[i]);
        while(q.size() > 0) {
            int x = q.back();
            if (dp[x] + sum[i + 1] - sum[x + 1] <= dp[i]) q.pop_back();
            else break;
        }
        q.push_back(i);
    }
    cout << res << endl;
    return 0;
}