#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> S(M, 0);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int c; cin >> c;
            if (c == 1) {
                S[i] |= (1 << j);
            }
        }
    }

    const long long INF = (1LL << 60);
    int FULL = (1 << N) - 1;


    int cover = 0;
    for (int s : S) cover |= s;
    if (cover != FULL) { cout << -1 << "\n"; return 0; }

    vector<long long> dp(1 << N, INF), ndp;
    dp[0] = 0;

    for (int i = 0; i < M; ++i) {
        ndp = dp;
        for (int mask = 0; mask <= FULL; ++mask) {
            if (dp[mask] == INF) continue;
            int nmask = mask | S[i];
            ndp[nmask] = min(ndp[nmask], dp[mask] + 1);
        }
        dp.swap(ndp);
    }

    long long ans = dp[FULL];
    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0;
}
