#include <bits/stdc++.h>
using namespace std;

int main() {
    int D;
    cin >> D;

    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }

    vector<vector<int>> s(D, vector<int>(26));
    for (int d = 0; d < D; d++) {
        for (int i = 0; i < 26; i++) {
            cin >> s[d][i];
        }
    }

    vector<int> t(D);
    for (int d = 0; d < D; d++) {
        cin >> t[d];
        t[d]--; // 1〜26 を 0〜25 に変換
    }

    long long score = 0;

    // last[i] = 类型 i 上一次举办的日期
    // 程序里日期用 0-based，所以没举办过设为 -1
    vector<int> last(26, -1);

    for (int d = 0; d < D; d++) {
        int contest = t[d];

        // 1. 第 d 天举办 contest，增加满意度
        score += s[d][contest];

        // 2. 更新这个比赛类型的最后举办日期
        last[contest] = d;

        // 3. 每种比赛都扣分
        for (int i = 0; i < 26; i++) {
            score -= 1LL * c[i] * (d - last[i]);
        }

        // 4. 输出第 d 天结束时的满意度
        cout << score << endl;
    }

    return 0;
}