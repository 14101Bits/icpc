#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    string ans = "";
    int n = s.length();
    int m = t.length();

    for (int i = n - m; i >= 0; i--) {
        bool can = true;

        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                can = false;
                break;
            }
        }

        if (can) {
            string after = s;

            for (int j = 0; j < m; j++) {
                after[i + j] = t[j];
            }

            for (int k = 0; k < n; k++) {
                if (after[k] == '?') {
                    after[k] = 'a';
                }
            }

            ans = after;
            break;
        }
    }

    if (ans == "") {
        ans = "UNRESTORABLE";
    }

    cout << ans << "\n";

    return 0;
}