//
// https://atcoder.jp/contests/abc205/tasks/abc205_d
//
#include <bits/stdc++.h>
using namespace std;


long long count_not_in_A(const vector<long long>& A, long long x) {
    // upper_bound: x より大きい最初の要素の位置
    long long removed = upper_bound(A.begin(), A.end(), x) - A.begin();
    // 全体 x 個のうち、A に含まれる removed 個を除いた残りが答え
    return x - removed;
}

long long find_kth(const vector<long long>& A, long long K) {
    long long L = 1, R = (long long)4e18;  // 十分大きい上限
    while (L < R) {
        long long M = L + (R - L) / 2;
        if (count_not_in_A(A, M) >= K)
            R = M;   // K 番目の数は M 以下
        else
            L = M + 1; // まだ足りない → もっと大きい数を探す
    }
    return L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < Q; ++i) {
        long long K;
        cin >> K;
        cout << find_kth(A, K) << '\n';
    }
    return 0;
}