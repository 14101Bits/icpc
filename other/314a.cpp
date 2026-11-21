#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int d;
        float r;
        double pi = acos(-1);
        double ans;
        cin >> d;
        if (d<0) {ans = 0;}
        else{
            r = (float)d/2;
            ans = pi * r * r;
        }

        cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}