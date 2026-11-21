//
// https://atcoder.jp/contests/arc088/tasks/arc088_b
//
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long x;
    cin >> N >> x;

    long long ans = 0;
    long long now_candy, next_candy;
    cin >> now_candy;

    for (int i = 1; i < N; i++) {
        cin >> next_candy;

        long long total = now_candy + next_candy;
        if (total > x) {
            long long remove = total - x;
            ans += remove;

            //  ext_candy first
            long long cut_next = min(remove, next_candy);
            next_candy -= cut_next;
            remove -= cut_next;

            if (remove > 0) {
                now_candy -= remove;
            }
        }

        now_candy = next_candy;
    }

    cout << ans << "\n";
    return 0;
}

