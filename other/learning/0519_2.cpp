#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    auto can = [&](ll x) {
        long long need = 0;

        for (int i = 1; i <= N; i++) {
            if (A[i] < x) {
                ll diff = x - A[i];
                need += (diff + i - 1) / i;
            }

            if (need > K) {
                return false;
            }
        }

        return need <= K;
    };

    ll ok = 0;
    ll ng = 4e18;

    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;

        if (can(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}