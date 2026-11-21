#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=3360
// 等差数列の和を計算する関数
// A から始まり、毎日 B ずつ減少する値を days 日間足し合わせる
// (A, A-B, A-2B, ... )
// 計算式: A*days - B * (days*(days-1)/2)
ll calc_sum(ll A, ll B, ll days) {
    if (days <= 0) return 0;
    return A * days - B * (days * (days - 1) / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;    // ゲームの種類数
        ll D;     // 日数
        cin >> N >> D;
        if (N == 0 && D == 0) break;

        vector<pair<ll,ll>> v(N);
        for (int i = 0; i < N; i++) {
            // v[i].first = A (初期値 = 最大値), v[i].second = B (減少量)
            cin >> v[i].first >> v[i].second;
        }

        // A の大きい順にソートする
        sort(v.rbegin(), v.rend());

        // N=1 の場合：同じゲームを毎日遊ぶ
        if (N == 1) {
            cout << calc_sum(v[0].first, v[0].second, D) << "\n";
            continue;
        }

        // 最大 A のゲーム (Game1)
        ll A1 = v[0].first, B1 = v[0].second;
        // 2 番目に大きい A のゲーム (Game2)
        ll A2 = v[1].first, B2 = v[1].second;

        ll ans = 0;

        // 交互に i 回 (2i 日) Game1 と Game2 を遊び，
        // 残りの日はすべて Game1 を遊ぶという戦略を考える
        for (ll i = 0; 2*i <= D; i++) {
            // 交互に遊ぶ部分の合計 (i 回 = 2i 日)
            ll cur = i * (A1 + A2);
            // 残り (D - 2i) 日は Game1 を連続で遊ぶ
            cur += calc_sum(A1, B1, D - 2*i);

            // 最大値を更新する
            ans = max(ans, cur);
        }

        // 答えを出力
        cout << ans << "\n";
    }
    return 0;
}
