#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1000000007;

    int N, M;
    cin >> N >> M;

    vector<bool> broken(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (broken[i]) {
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i - 1];
        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }

    cout << dp[N] % MOD << '\n';
    return 0;
}

//再帰