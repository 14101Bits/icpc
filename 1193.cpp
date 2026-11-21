#include <bits/stdc++.h>
using namespace std;
//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=1193
const int BLANK = 0;
// columns: 5列の盤面データ（下->上の順で格納）

// 1行をスキャンし、スコアを取得
int process(vector<vector<int>> &columns) {
    // 最大の高さを取得（すべての列で一番高い列の高さ）
    int maxHeight = 0;
    for (auto &col : columns) maxHeight = max(maxHeight, (int)col.size());

    // 消去する座標を保存
    struct Cell { int col; int height; };
    vector<Cell> toRemove;
    int roundScore = 0;

    // 行ごとにスキャン
    for (int h = 0; h < maxHeight; h++) {
        // 現在の行を作成（5列分）
        vector<int> row(5, BLANK);
        for (int c = 0; c < 5; c++) {
            if (h < (int)columns[c].size()) row[c] = columns[c][h];
        }

        // 横方向で同じ数字が3つ以上並んでいるか確認
        for (int i = 0; i < 5;) {
            if (row[i] == BLANK) { i++; continue; }
            int j = i;
            while (j + 1 < 5 && row[j + 1] == row[i]) j++;
            int len = j - i + 1;
            if (len >= 3) {
                roundScore += row[i] * len; // スコア加算
                for (int k = i; k <= j; k++) {
                    toRemove.push_back({k, h}); // 消去をマーク
                }
            }
            i = j + 1;
        }
    }

    // 消去処理
    if (!toRemove.empty()) {
        for (auto &cell : toRemove) {
            if (cell.height < (int)columns[cell.col].size()) {
                columns[cell.col][cell.height] = BLANK;
            }
        }
        // BLANKを取り除く（重力シミュレーション）
        for (auto &col : columns) {
            col.erase(remove(col.begin(), col.end(), BLANK), col.end());
        }
    }

    return roundScore;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int h;
        cin >> h;
        if (h == 0) break;

        vector<vector<int>> columns(5); // 5列の盤面

        // 入力を読み込む（gridに一旦格納）
        vector<vector<int>> grid(h, vector<int>(5));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }

        // gridからcolumnsへ変換（下から上に積み込む）
        for (int j = 0; j < 5; j++) {
            for (int i = h - 1; i >= 0; i--) {
                if (grid[i][j] != BLANK) {
                    columns[j].push_back(grid[i][j]);
                }
            }
        }

        // 連鎖処理
        int totalScore = 0;
        while (true) {
            int s = process(columns);
            if (s == 0) break;
            totalScore += s;
        }

        cout << totalScore << "\n";
    }

    return 0;
}
