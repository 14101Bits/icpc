//
// https://atcoder.jp/contests/arc088/tasks/arc088_b
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;
    int N = S.size();

    vector<int> blocks;
    for (int i = 0, j; i < N; i = j) {
        j = i;
        while (j < N && S[j] == S[i]) ++j;
        blocks.push_back(j - i);
    }

    if (blocks.size() == 1) {
        cout << N << '\n';  // 全0或全1都可取K=N
        return 0;
    }

    int m = blocks.size();
    int ans = INT_MAX;

    for (int i = 0; i + 1 < m; ++i) {
        ans = min(ans, blocks[i] + blocks[i + 1]);
    }
    if (S.front() == '1') ans = min(ans, blocks[0]);
    if (S.back()  == '1') ans = min(ans, blocks.back());

    cout << ans << '\n';
    return 0;
}

