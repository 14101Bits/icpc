#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int q = partition(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        if (i == q) cout << "[";
        cout << array[i];
        if (i == q) cout << "]";
    }

    cout << "\n";
    return 0;
}