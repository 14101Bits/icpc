#include <bits/stdc++.h>
using namespace std;

//https://onlinejudge.u-aizu.ac.jp/services/ice/?problemId=1650
//模擬解答を参考

const int INF = 1e9; //非常に大きな値

struct Node {
    char op; // '+', '-', or '@' (葉ノード)
    int val; // if op == '@'
    vector<int> children;
};

const int MAX_NODE = 500005;
const int MAX_DEPTH = 105;

char expr[MAX_NODE]; // expression 入力された式を格納する文字列（例："(+ 1 (- 2 3))"）
Node tree[MAX_NODE]; // 構文木
int dp_max[MAX_NODE], dp_min[MAX_NODE]; // 各ノードにおける部分木の最大値・最小値を表す
int ans_max[MAX_NODE], ans_min[MAX_NODE]; // 各ノードを「根」に持ってきたときの、全体の最大値・最小値
int pre_max[MAX_NODE], pre_min[MAX_NODE]; // 親ノード側の情報を使って、自分を根にしたときに必要な補助データ
vector<int> op_pos_by_depth[MAX_DEPTH]; // 各深さごとに、'+', '-' の演算子が出現する位置
int node_cnt = 0; // ノード数を管理するカウンター

// 葉ノード
int make_leaf(int val) {
    ++node_cnt;
    tree[node_cnt].op = '@';
    tree[node_cnt].val = val;
    return node_cnt;
}

// 构造表达式
int parse_expr(int l, int r, int depth);
// l〜rの部分式を、優先順位が低い演算子（+や-）に基づいて解析する関数
// depth：現在の括弧の深さ（V[depth] を使うために渡す）
// 戻り値：tree[]配列に構築されたノードのインデックス
int parse_factor(int l, int r, int depth);
// 数字や括弧で囲まれた小さい式を処理する関数
// 基本的に「葉ノード」になる数字か、もう一つの `parse_expr` を呼ぶ
// 戻り値：tree[]配列に構築されたノードのインデックス

int parse_expr(int l, int r, int depth) {
    vector<int> ops; //depth +-の位置
    auto& v = op_pos_by_depth[depth];
    int L = lower_bound(v.begin(), v.end(), l) - v.begin();
    int R = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;

    for (int i = L; i <= R; i++) ops.push_back(v[i]);

    if (ops.empty()) return parse_factor(l, r, depth);

    if (depth == 0) {
        tree[0].op = expr[ops[0]];
        tree[0].children.push_back(parse_factor(l, ops[0] - 1, depth));
        tree[0].children.push_back(parse_factor(ops[0] + 1, ops[1] - 1, depth));
        tree[0].children.push_back(parse_factor(ops[1] + 1, r, depth));
        return 0;
    } else {
        ++node_cnt;
        int cur = node_cnt;
        tree[cur].op = expr[ops[0]];
        tree[cur].children.push_back(parse_factor(l, ops[0] - 1, depth));
        tree[cur].children.push_back(parse_factor(ops[0] + 1, r, depth));
        return cur;
    }
}

int parse_factor(int l, int r, int depth) {
    if (isdigit(expr[l])) return make_leaf(expr[l] - '0');
    return parse_expr(l + 1, r - 1, depth + 1);
}

// 子ノードの最大値と最小値
void dfs(int node) {
    if (tree[node].op == '@') {
        dp_min[node] = dp_max[node] = tree[node].val;
        return;
    }

    for (int child : tree[node].children) dfs(child);

    if (tree[node].op == '+') {
        dp_min[node] = dp_max[node] = 0;
        for (int child : tree[node].children) {
            dp_min[node] += dp_min[child];
            dp_max[node] += dp_max[child];
        }
    } else { // '-'
        dp_max[node] = -INF;
        dp_min[node] = INF;

        for (int i = 0; i < tree[node].children.size(); i++) {
            int left = tree[node].children[i];
            int max_val = dp_max[left], min_val = dp_min[left];

            for (int j = 0; j < tree[node].children.size(); j++) {
                if (i == j) continue;
                int right = tree[node].children[j];
                max_val -= dp_min[right];
                min_val -= dp_max[right];
            }

            dp_max[node] = max(dp_max[node], max_val);
            dp_min[node] = min(dp_min[node], min_val);
        }
    }
}


void dfs2(int node, int parent) {
    if (node == 0) {
        ans_max[node] = dp_max[node];
        ans_min[node] = dp_min[node];
    } else {
        if (tree[node].op == '@') return;

        if (tree[parent].op == '+') {
            pre_max[node] = ans_max[parent] - dp_max[node];
            pre_min[node] = ans_min[parent] - dp_min[node];
        } else { //-
            if (parent == 0) {
                vector<int> rest;
                for (int c : tree[parent].children) if (c != node) rest.push_back(c);

                pre_max[node] = max(
                    dp_max[rest[0]] - dp_min[rest[1]],
                    dp_max[rest[1]] - dp_min[rest[0]]
                );
                pre_min[node] = min(
                    dp_min[rest[0]] - dp_max[rest[1]],
                    dp_min[rest[1]] - dp_max[rest[0]]
                );
            } else {
                int sibling; //兄弟
                for (int c : tree[parent].children) {
                    if (c != node) {
                        sibling = c;
                        break;
                    }
                }

                pre_max[node] = max(
                    dp_max[sibling] - pre_min[parent],
                    pre_max[parent] - dp_min[sibling]
                );
                pre_min[node] = min(
                    dp_min[sibling] - pre_max[parent],
                    pre_min[parent] - dp_max[sibling]
                );
            }
        }

        if (tree[node].op == '+') {
            ans_max[node] = dp_max[node] + pre_max[node];
            ans_min[node] = dp_min[node] + pre_min[node];
        } else { //-
            int a = tree[node].children[0];
            int b = tree[node].children[1];

            // 最大値の計算：
            // パターン1: a - b - 親から来た値（a最大、b+pre最小）
            // パターン2: b - a - 親から来た値（b最大、a+pre最小）
            // パターン3: 親から来た値 - a - b（pre最大、a+b最小）
            ans_max[node] = max({
                dp_max[a] - (dp_min[b] + pre_min[node]),
                dp_max[b] - (dp_min[a] + pre_min[node]),
                pre_max[node] - (dp_min[a] + dp_min[b])
            });
            // 最小値の計算：
            // パターン1: a - b - 親から来た値（a最小、b+pre最大）
            // パターン2: b - a - 親から来た値（b最小、a+pre最大）
            // パターン3: 親から来た値 - a - b（pre最小、a+b最大）
            ans_min[node] = min({
                dp_min[a] - (dp_max[b] + pre_max[node]),
                dp_min[b] - (dp_max[a] + pre_max[node]),
                pre_min[node] - (dp_max[a] + dp_max[b])
            });
        }
    }

    for (int child : tree[node].children) dfs2(child, node);
}

void solve() {
    //初期化
    for (int i = 0; i < MAX_DEPTH; i++) op_pos_by_depth[i].clear();
    for (int i = 0; i < MAX_NODE; i++) tree[i].children.clear();

    int len = strlen(expr);
    int depth = 0;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') depth++;
        else if (expr[i] == ')') depth--;
        else if (expr[i] == '+' || expr[i] == '-') op_pos_by_depth[depth].push_back(i);
    }

    node_cnt = 0;
    parse_expr(0, len - 1, 0);

    for (int i = 0; i <= node_cnt; i++) {
        dp_min[i] = ans_min[i] = INF;
        dp_max[i] = ans_max[i] = -INF;
    }

    dfs(0);
    dfs2(0, -1);

    int res = -INF;
    for (int i = 0; i <= node_cnt; i++) {
        if (tree[i].op != '@') res = max(res, ans_max[i]);
    }

    printf("%d\n", res);
}

int main() {
    while (true) {
        scanf("%s", expr);
        if (strcmp(expr, "-1") == 0) break;
        solve();
    }
    return 0;
}
