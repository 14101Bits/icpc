
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXV = 3000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];

    vector<int> dp(MAXV + 1, 0), ndp(MAXV + 1, 0), pref(MAXV + 1, 0);

    for (int x = a[1]; x <= b[1]; x++) {
        dp[x] = 1;
    }

    for (int i = 2; i <= N; i++) {
        pref[0] = dp[0];
        for (int x = 1; x <= MAXV; x++) {
            pref[x] = pref[x - 1] + dp[x];
            if (pref[x] >= MOD) pref[x] -= MOD;
        }

        for (int x = 0; x <= MAXV; x++) {
            if (a[i] <= x && x <= b[i]) ndp[x] = pref[x];
            else ndp[x] = 0;
        }

        dp.swap(ndp);
    }

    int ans = 0;
    for (int x = 0; x <= MAXV; x++) {
        ans += dp[x];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
    return 0;
}
