
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
#include<iostream>
using namespace std;

static pair<int, int> dp_range(int x, int N, int L, int D) {
    int lleft = x * D;
    int hleft = x * (D + 1);
    int lright = L - (N - 1 - x) * (D + 1);
    int hright = L - (N - 1 - x) * D;
    return make_pair(max(lleft, lright), min(hleft, hright));
}

int main() {

    vector<int> start;
    vector<int> dp, old;
    int N, L, D;

    cin >> N >> L;
    D = L / (N - 1);
    start.resize(N);
    for (int i = 0; i < N; i++) cin >> start[i];

    if (N == 1) {
        cout << "0\n";
        return 0;
    }

    dp.resize(L + 1);
    old.resize(L + 1);
    dp[0] = start[0];
    for (int i = 1; i < N; i++) {
        swap(dp, old);
        pair<int, int> oldr = dp_range(i - 1, N, L, D);
        pair<int, int> r = dp_range(i, N, L, D);
        for (int j = r.first; j <= r.second; j++) {
            dp[j] = INT_MAX;
            if (j - (D + 1) >= oldr.first) dp[j] = min(dp[j], old[j - (D + 1)]);
            if (j - D <= oldr.second) dp[j] = min(dp[j], old[j - D]);
            dp[j] += abs(start[i] - j);
        }
    }

    cout << dp[L] << "\n";
    return 0;
}

