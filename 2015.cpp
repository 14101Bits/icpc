#include <bits/stdc++.h>
using namespace std;

// y 1-100000 c 1000000000 y < 100

//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=2015

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_SUM = 1500000; // 1500 * 1000
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        // vector を使って出現回数をカウントする
        vector<int> n_freq(MAX_SUM + 1, 0);
        vector<int> m_freq(MAX_SUM + 1, 0);

        vector<int> n_prefix(n + 1, 0);
        vector<int> m_prefix(m + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            n_prefix[i + 1] = n_prefix[i] + x;
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            m_prefix[i + 1] = m_prefix[i] + x;
        }

        // 高さ方向の連続区間の和をカウント
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = n_prefix[j] - n_prefix[i];
                n_freq[sum]++;
            }
        }

        // 幅方向の連続区間の和をカウント
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j <= m; j++) {
                int sum = m_prefix[j] - m_prefix[i];
                m_freq[sum]++;
            }
        }

        // 正方形の個数を計算
        long long result = 0;
        for (int s = 1; s <= MAX_SUM; s++) {
            if (n_freq[s] && m_freq[s]) {
                result += (long long)n_freq[s] * m_freq[s];
            }
        }

        cout << result << "\n";
    }

    return 0;
}
