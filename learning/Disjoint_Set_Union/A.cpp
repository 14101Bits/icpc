// https://atcoder.jp/contests/practice2/tasks/practice2_a

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // 路径压缩
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return;

        // 小集合接到大集合下面
        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            dsu.unite(u, v);
        } else {
            cout << (dsu.same(u, v) ? 1 : 0) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}