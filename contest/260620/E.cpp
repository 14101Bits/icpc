#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll Y;
    cin >> N >> M >> Y;

    int WARP = N; // 虚拟点编号
    vector<vector<pair<int, ll>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        u--, v--;

        graph[u].push_back({v, t});
        graph[v].push_back({u, t});
    }

    vector<ll> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    // 加ワープ边
    for (int i = 0; i < N; i++) {
        graph[i].push_back({WARP, X[i]});
        graph[WARP].push_back({i, X[i] + Y});
    }

    vector<ll> dist(N + 1, INF);
    dist[0] = 0;

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (auto [to, cost] : graph[v]) {
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (i > 1) cout << " ";
        cout << dist[i];
    }
    cout << '\n';

    return 0;
}