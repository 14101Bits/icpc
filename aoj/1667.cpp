#include <bits/stdc++.h>
using namespace std;

#define MAXS 100   // 最大データセット数
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=1667
//Gray Code?!
// 100内最大＝＞6


int solve(int n, const string& s) {
    // 試す問題数 k を 1 から n まで順に増やしていく（小さい方が望ましいので）
    for (int k = 1; k <= n; ++k) {

        bool found = false; // 条件を満たす組み合わせが見つかったかどうか
        vector<int> tmp;    // 現在構築中の配点の組み合わせ

        // 匿名再帰関数 dfs(rem: 残りの合計点, left: 残りの問題数, last: 前回使用した点数以上のみ使うことで単調増加を保つ)
        function<void(int, int, int)> dfs = [&](int rem, int left, int last) {
            if (found) return; // 既に見つかったら再探索不要

            // 問題数をすべて使い切った
            if (left == 0) {
                // しかも残り点数も 0 なら有効な配点組み合わせ
                if (rem == 0) {
                    // 到達可能スコアを bitset で表現
                    bitset<101> reachable;
                    reachable[0] = 1; // 0点

                    // 各問題の配点を順に反映していく（部分和DP）
                    for (int p : tmp) {
                        reachable |= reachable << p; // スコアを p 加えると、reachable の各位置が p 右に移動して到達できるスコアになる
                    }

                    // すべての「o」の位置のスコアが reachable に含まれるかチェック
                    for (int i = 0; i <= n; ++i) {
                        if (s[i] == 'o' && !reachable[i]) return; // 必要なスコアが作れない → 不合格
                    }

                    found = true;
                }
                return;
            }

            // 次に選ぶ点数は last 以上でなければならない（重複を防ぐため単調増加）
            for (int i = last; i <= rem; ++i) {
                tmp.push_back(i);                // 配点 i を追加
                dfs(rem - i, left - 1, i);       // 残り rem-i 点を left-1 問で割り振る
                tmp.pop_back();                 // バックトラック（元に戻す）
            }
        };

        dfs(n, k, 1); // 最初は rem=n, left=k, 最初の点数は1からスタート（1点以上）

        if (found) return k; // 最小の k が見つかったので即リターン
    }

    return -1; // 見つからない
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < MAXS; ++i) {
        int n;
        if (!(cin >> n)) break;
        if (n == 0) break;

        string s;
        cin >> s;

        cout << solve(n, s) << "\n";
    }

    return 0;
}
