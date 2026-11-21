#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<pair<int, int>> points; //  H,L:

    for (int i = 1; i <= N; i++) {
        int  H,L;
        cin>>H>>L;
        points.push_back(make_pair(H,L));
    }

        sort(points.begin(), points.end(), [](auto a, auto b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    vector<int> candH;
    vector<int> candL;
    int maxL = -1;

    for (auto [H, L] : points) {
        if (L > maxL) {
            candH.push_back(H);
            candL.push_back(L);
            maxL = L;
        }
    }

    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int T;
        cin >>T;
        int pos = upper_bound(candL.begin(), candL.end(), T) - candL.begin();
        cout << candH[pos] << endl;
    }

        return 0;
    }