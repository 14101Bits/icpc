#include <bits/stdc++.h>
using namespace std;
#define MAXS 50 // 最大データセット数
#define END "#"
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=3358
// 文字の種類を判定：英小文字 < 英大文字 < 数字
int getCategory(char c) {
    if (islower(c)) return 1;   // 英小文字
    if (isupper(c)) return 2;   // 英大文字
    if (isdigit(c)) return 3;   // 数字
    return 4;                   // それ以外
}

// カスタム比較関数
bool customCompare(char a, char b) {
    int ca = getCategory(a);
    int cb = getCategory(b);
    if (ca != cb) return ca < cb; // カテゴリ順に並べる
    return a < b;                 // 同じカテゴリならASCII順
}

// ソート処理を行う関数
string dealer(string s) {
    sort(s.begin(), s.end(), customCompare);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    for (int i = 0; i < MAXS; i++) { // 最大50回まで処理
        if (!(cin >> s)) break;      // 入力が終わったら終了
        if (s == END) break;         // '#' が来たら終了
        cout << dealer(s) << "\n";   // 並び替えた結果を出力
    }
    return 0;
}
