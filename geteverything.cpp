
//
// https://atcoder.jp/contests/abc142/tasks/abc142_e
//
#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; //12
    if(!(cin >> N >> M)) return 0;
    vector<long long> a(M);
    vector<int> S(M, 0);
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> a[i] >> b;
        for (int j = 0; j < b; ++j) {
            int c; cin >> c;        // 1..N
            --c; S[i] |= (1<<c);
        }
    }
    const long long INF = (1LL<<60);
    int FULL = (1<<N) - 1;
    vector<long long> dp(1<<N, INF), ndp;
    dp[0] = 0;
    for (int i = 0; i < M; ++i) {
        ndp = dp;
        for (int mask = 0; mask <= FULL; ++mask) {
            if (dp[mask] == INF) continue;
            int nmask = mask | S[i];
            ndp[nmask] = min(ndp[nmask], dp[mask] + a[i]);
        }
        dp.swap(ndp);
    }
    long long ans = dp[FULL];
    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0;
}
