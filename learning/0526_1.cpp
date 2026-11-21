#include <bits/stdc++.h>
using namespace std;

int main() {
    int D;
    cin >> D;

    vector<int> c(26);
    for (int i = 0; i < 26; i++) cin >> c[i];

    vector<vector<int>> s(D, vector<int>(26));
    for (int d = 0; d < D; d++) {
        for (int i = 0; i < 26; i++) {
            cin >> s[d][i];
        }
    }

    vector<int> last(26, 0);
    long long score = 0;

    for (int d = 1; d <= D; d++) {
        int best_type = 0;
        long long best_score = LLONG_MIN;

        for (int t = 0; t < 26; t++) {
            vector<int> temp_last = last;
            temp_last[t] = d;

            long long temp_score = score;

            temp_score += s[d - 1][t];

            for (int i = 0; i < 26; i++) {
                temp_score -= 1LL * c[i] * (d - temp_last[i]);
            }

            if (temp_score > best_score) {
                best_score = temp_score;
                best_type = t;
            }
        }

        cout << best_type + 1 << endl;

        score += s[d - 1][best_type];
        last[best_type] = d;

        for (int i = 0; i < 26; i++) {
            score -= 1LL * c[i] * (d - last[i]);
        }
    }

    return 0;
}