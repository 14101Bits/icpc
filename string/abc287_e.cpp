#include <bits/stdc++.h>
using namespace std;

int lcp(const string& a, const string& b) {
    int len = min(a.size(), b.size());
    int cnt = 0;

    while (cnt < len && a[cnt] == b[cnt]) {
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<string, int>> v;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back({s, i});
    }

    sort(v.begin(), v.end());

    vector<int> ans(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int x = lcp(v[i].first, v[i + 1].first);

        int id1 = v[i].second;
        int id2 = v[i + 1].second;

        ans[id1] = max(ans[id1], x);
        ans[id2] = max(ans[id2], x);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}