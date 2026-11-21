#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char empty = 'o';
    int N;
    char X;
    cin>>N>>X;
    int position = int(X) - int('A');
    for (int i = 1; i <= N; i++) {
    string s;
    cin>>s;
    if (s[position] == empty) {
    cout<<"Yes"<<endl;
    return 0;
    }
    }
    cout << "No" << endl;

    return 0;
}