#include <bits/stdc++.h>
using namespace std;
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=3359
// y 1-100000 c 1000000000 y < 100

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        long long y, c, r;
        cin >> y >> c >> r;
        if (y == 0 && c == 0 && r == 0) break;

        long long result = 0; // 最後の年末に必要な資産
        for (int i = 0; i < y; i++) {
            // 逆推
            result = (result* 100 + (100 + r) - 1) / (100 + r); // 向上取整
            result += c;
        }
        cout << need << "\n";
    }
    return 0;
}