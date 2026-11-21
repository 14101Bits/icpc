#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X,Y;
    cin>>X>>Y;
    int res = 16*Y - 9 *X;
    if (res == 0){
        cout << "Yes"<< endl;
    }
    else{
        cout << "No" << endl;}

    return 0;
}