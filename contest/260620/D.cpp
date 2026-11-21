#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;
    vector<long long> score(N + 1);
    const long long NEG = -4e18;
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, NEG));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
    int L,R;
    cin>>L>>R;

    }
}

    return 0;
}
int gapLen(int L1, int R1, int L2, int R2) {
    if (L1 > L2) {
        swap(L1, L2);
        swap(R1, R2);
    }
    return max(0, L2 - R1);
}

}