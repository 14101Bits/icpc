#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

// 高斯消元で rank を求める & 矛盾を確認
int gaussian_rank(vector<vector<double>> &A, int vars) {
    int n = A.size();       // 行数
    int m = A[0].size();    // 列数 (vars+1)
    int rank = 0;

    for (int col = 0; col < vars && rank < n; col++) {
        // pivot を探す
        int pivot = -1;
        for (int i = rank; i < n; i++) {
            if (fabs(A[i][col]) > EPS) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) continue;

        swap(A[rank], A[pivot]);

        // pivot 行を正規化
        double div = A[rank][col];
        for (int j = col; j < m; j++) A[rank][j] /= div;

        // 他の行の pivot 列を消去
        for (int i = 0; i < n; i++) {
            if (i != rank && fabs(A[i][col]) > EPS) {
                double factor = A[i][col];
                for (int j = col; j < m; j++) {
                    A[i][j] -= factor * A[rank][j];
                }
            }
        }
        rank++;
    }

    // 矛盾チェック: 0 0 ... 0 | 非0
    for (int i = rank; i < n; i++) {
        bool allZero = true;
        for (int j = 0; j < vars; j++) {
            if (fabs(A[i][j]) > EPS) { allZero = false; break; }
        }
        if (allZero && fabs(A[i][vars]) > EPS) {
            return -1; // 矛盾
        }
    }
    return rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int vars = w + h - 1;
        int k = vars;

        vector<vector<double>> A(k, vector<double>(vars + 1, 0));

        for (int i = 0; i < k; i++) {
            int x, y, n;
            cin >> x >> y >> n;

            // col[x] -> (x-1)
            A[i][x - 1] = 1;

            // row[y] -> y > 1 の場合、位置 (w + y - 2)
            if (y > 1) {
                int idx = w + (y - 2);
                A[i][idx] = 1;
            }

            A[i][vars] = n; // 定数項
        }

        int rank = gaussian_rank(A, vars);
        if (rank == -1) {
            cout << "NO\n"; // 矛盾：無解
        } else if (rank == vars) {
            cout << "YES\n"; // 一意解
        } else {
            cout << "NO\n"; // 無限解
        }
    }
    return 0;
}
