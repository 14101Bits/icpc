#include <bits/stdc++.h>
using namespace std;
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=3204

// 与えられた括弧列 s に対して、前に left_add 個の '(' を追加すれば
// 「そこそこバランスのとれた括弧列」になるかどうかを判定する関数
bool check_balance(const string& s, int left_add) {
    int cur = left_add;
    int n = s.size();
    int i = 0;
    while (i < n) {
        if (s[i] == '(') {
            cur++;
            i++;
            continue;
        }

        // s[i] が ')' の場合
        if (cur == 0) return false;
        cur--;
        i++;

        // 連続する2つの ')' を許容（最大2個まで）
        if (i < n && s[i] == ')') {
            i++;
        }
    }
    return true;
}

// s をそこそこバランスにするために必要な '(' の最小追加数を求める関数
int min_add_left(const string& s) {
    int ok = s.size() * 2;
    int ng = -1;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (check_balance(s, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        if (s == "#") break;

        // 左側に追加する括弧数を求める
        int res = min_add_left(s);

        // 文字列を反転し、'(' と ')' を入れ替えて右側の補完を同様に処理
        reverse(s.begin(), s.end());
        for (char& c : s) {
            c = (c == '(' ? ')' : '(');
        }

        // 右側に追加する括弧数を求める
        res += min_add_left(s);

        // 結果を出力
        cout << res << '\n';
    }

    return 0;
}
