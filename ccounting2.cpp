#include <bits/stdc++.h>
using namespace std;


int first_ge(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size();          // [l, r)
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] >= target) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> B = A;
    sort(B.begin(), B.end());

    for (int j = 0; j < Q; ++j) {
        int x; cin >> x;
        int idx = first_ge(B, x);
        int ans = (int)B.size() - idx;
        cout << ans << '\n';
    }
    return 0;
}
