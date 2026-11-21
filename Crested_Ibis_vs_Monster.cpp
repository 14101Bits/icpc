#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, N;
    cin >> H >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    const int INF = 1e9;
    vector<int> dp(H + 1, INF);
    dp[0] = 0;

    for (int j = 1; j <= H; j++) {
        for (int i = 0; i < N; i++) {
            dp[j] = min(dp[j], dp[max(0, j - a[i])] + b[i]);
        }
    }

    cout << dp[H] << '\n';
    return 0;
}