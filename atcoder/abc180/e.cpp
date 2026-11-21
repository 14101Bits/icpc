
//
// https://atcoder.jp/contests/abc180/tasks/abc180_e
//
#include <bits/stdc++.h>
using namespace std;

static inline long long get_cost(long long a,long long b,long long c,
                                 long long p,long long q,long long r){
    return llabs(p-a) + llabs(q-b) + max(0LL, r-c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;
    vector<long long> X(N), Y(N), Z(N);
    for(int i=0;i<N;++i) cin >> X[i] >> Y[i] >> Z[i];

    // 预计算边权
    vector<vector<long long>> cost(N, vector<long long>(N, 0));
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(i!=j) cost[i][j] = get_cost(X[i],Y[i],Z[i], X[j],Y[j],Z[j]);

    const long long INF = (1LL<<60);
    int FULL = (1<<N) - 1;

    // dp[mask][v]
    vector<vector<long long>> dp(1<<N, vector<long long>(N, INF));
    dp[1<<0][0] = 0;

    for(int mask=0; mask<=FULL; ++mask){
        for(int v=0; v<N; ++v){
            long long cur = dp[mask][v];
            if(cur==INF) continue;
            // 试着去下一个未访问的城市 u
            for(int u=0; u<N; ++u){
                if(mask & (1<<u)) continue;
                int nmask = mask | (1<<u);
                dp[nmask][u] = min(dp[nmask][u], cur + cost[v][u]);
            }
        }
    }

    long long ans = INF;
    for(int v=0; v<N; ++v){
        ans = min(ans, dp[FULL][v] + cost[v][0]); // 回到城市0
    }
    cout << ans << "\n";
    return 0;
}
