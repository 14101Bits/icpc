#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<array<int, 26>> nex;
    vector<int> pass;

    Trie() {
        nex.push_back({});
        pass.push_back(0);
    }

    int new_node() {
        nex.push_back({});
        pass.push_back(0);
        return (int)nex.size() - 1;
    }

    long long insert(const string& s) {
        int p = 0;
        long long res = 0;

        for (char ch : s) {
            int c = ch - 'a';

            if (nex[p][c] == 0) {
                nex[p][c] = new_node();
            }

            p = nex[p][c];
            res += pass[p];
            pass[p]++;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Trie t;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ans += t.insert(s);
    }

    cout << ans << '\n';

    return 0;
}