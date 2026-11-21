#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> run_length(string s) {
    vector<pair<char, int>> res;

    int n = s.size();
    int i = 0;

    while (i < n) {
        char c = s[i];
        int cnt = 0;

        while (i < n && s[i] == c) {
            cnt++;
            i++;
        }

        res.push_back({c, cnt});
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    auto A = run_length(S);
    auto B = run_length(T);

    if (A.size() != B.size()) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < A.size(); i++) {
        char c1 = A[i].first;
        int cnt1 = A[i].second;

        char c2 = B[i].first;
        int cnt2 = B[i].second;

        if (c1 != c2) {
            cout << "No\n";
            return 0;
        }

        if (cnt1 > cnt2) {
            cout << "No\n";
            return 0;
        }

        if (cnt1 == 1 && cnt2 != 1) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}