#include <bits/stdc++.h>
using namespace std;
// using ai
using ll = long long;

const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> A(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> A[2 * i] >> A[2 * i + 1];
    }

    ll M = *max_element(A.begin(), A.end());

    ll inv2 = (MOD + 1) / 2;

    // 階乗・逆階乗
    vector<ll> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    auto C = [&](int n, int k) -> ll {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };

    // 整数の逆元
    vector<ll> inv(2 * N + 5);
    inv[1] = 1;
    for (int i = 2; i < (int)inv.size(); i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }

    // invpow2[i] = (1/2)^i
    vector<ll> invpow2(N + 1);
    invpow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        invpow2[i] = invpow2[i - 1] * inv2 % MOD;
    }

    // G(n, b) = E[ 1 / (b + X) ], X ~ Binomial(n, 1/2)
    auto G = [&](int n, int b) -> ll {
        if (n < 0) return 0;

        ll res = 0;
        for (int k = 0; k <= n; k++) {
            ll add = C(n, k) * inv[b + k] % MOD;
            res += add;
            if (res >= MOD) res -= MOD;
        }

        res = res * invpow2[n] % MOD;
        return res;
    };

    // cnt1: M がちょうど1人いる試合数
    // cnt2: M が2人いる試合数
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < N; i++) {
        int l = 2 * i;
        int r = 2 * i + 1;

        int c = 0;
        if (A[l] == M) c++;
        if (A[r] == M) c++;

        if (c == 1) cnt1++;
        if (c == 2) cnt2++;
    }

    vector<ll> ans(2 * N, 0);

    // --------------------
    // 最終優勝ラインが M+1 の場合
    // --------------------

    ll g_single = 0;
    ll g_double = 0;

    if (cnt1 >= 1) {
        // 自分が M vs 非M の M 側で勝つ場合
        g_single = G(cnt1 - 1, cnt2 + 1);
    }

    if (cnt2 >= 1) {
        // 自分が M vs M で勝つ場合
        g_double = G(cnt1, cnt2);
    }

    for (int i = 0; i < N; i++) {
        int l = 2 * i;
        int r = 2 * i + 1;

        int c = 0;
        if (A[l] == M) c++;
        if (A[r] == M) c++;

        for (int p : {l, r}) {
            if (A[p] != M) continue;

            if (c == 1) {
                ans[p] += inv2 * g_single % MOD;
            } else if (c == 2) {
                ans[p] += inv2 * g_double % MOD;
            }

            ans[p] %= MOD;
        }
    }

    // --------------------
    // 最終優勝ラインが M の場合
    // --------------------
    // M vs M があると、必ず誰かが M+1 になるので、この場合は存在しない

    if (cnt2 == 0) {
        int base = 0;
        int random_pairs = 0;

        // base: 確定で M 点になる人数
        // random_pairs: M-1 vs それ以下 の試合数
        for (int i = 0; i < N; i++) {
            int l = 2 * i;
            int r = 2 * i + 1;

            int cntM = 0;
            int cntM1 = 0;

            if (A[l] == M) cntM++;
            if (A[r] == M) cntM++;

            if (A[l] == M - 1) cntM1++;
            if (A[r] == M - 1) cntM1++;

            if (cntM == 1) {
                // M 側が負けても M 点で残る
                base++;

                // 相手が M-1 なら、M が負けることで相手も M 点になる
                if (cntM1 == 1) base++;
            } else {
                if (cntM1 == 2) {
                    // M-1 vs M-1 は必ず片方が M 点になる
                    base++;
                } else if (cntM1 == 1) {
                    // M-1 vs それ以下 は、M-1 側が勝てば M 点
                    random_pairs++;
                }
            }
        }

        ll factor = invpow2[cnt1]; // すべての M 選手が負ける確率
        ll g_base = G(random_pairs, base);
        ll g_win = G(random_pairs - 1, base + 1);

        for (int i = 0; i < N; i++) {
            int l = 2 * i;
            int r = 2 * i + 1;

            for (int p : {l, r}) {
                int q = l + r - p;

                if (A[p] == M) {
                    ans[p] += factor * g_base % MOD;
                } else if (A[p] == M - 1) {
                    if (A[q] == M) {
                        ans[p] += factor * g_base % MOD;
                    } else if (A[q] == M - 1) {
                        ans[p] += factor * inv2 % MOD * g_base % MOD;
                    } else {
                        ans[p] += factor * inv2 % MOD * g_win % MOD;
                    }
                }

                ans[p] %= MOD;
            }
        }
    }

    for (int i = 0; i < 2 * N; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}