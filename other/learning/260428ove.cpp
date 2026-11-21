#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to;     // 终点
    int cap;    // 剩余容量
    int cost;   // 单位费用
    int rev;    // 反向边在 G[to] 中的位置
};

vector<vector<Edge>> G;

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back({to, cap, cost, (int)G[to].size()});
    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int F) {
    int V = G.size();
    int res = 0;

    while (F > 0) {
        vector<int> dist(V, INF);
        vector<int> prevv(V, -1);
        vector<int> preve(V, -1);
        vector<bool> inqueue(V, false);

        queue<int> q;
        dist[s] = 0;
        q.push(s);
        inqueue[s] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            inqueue[v] = false;

            for (int i = 0; i < (int)G[v].size(); i++) {
                Edge &e = G[v][i];

                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    prevv[e.to] = v;
                    preve[e.to] = i;

                    if (!inqueue[e.to]) {
                        q.push(e.to);
                        inqueue[e.to] = true;
                    }
                }
            }
        }

        if (dist[t] == INF) {
            return -1; // F 流せない場合
        }

        int d = F;

        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }

        F -= d;
        res += d * dist[t];

        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

int main() {
    int V, E, F;
    cin >> V >> E >> F;

    G.resize(V);

    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        add_edge(u, v, c, d);
    }

    int ans = min_cost_flow(0, V - 1, F);
    cout << ans << "\n";

    return 0;
}9