
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <queue>
#include <assert.h>
#include <cstring>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        // 并查集初始化
        fa.resize(n * m);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(n * m, 1);

        // 构造并查集
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (i < n - 1 && grid[i+1][j] == '1') merge(i * n + j, (i + 1) * n + j);
                    if (j < m - 1 && grid[i][j+1] == '1') merge(i * n + j, i * n + j + 1);
                }
            }
        }

        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res.insert(find(i * n + j));
                }
            }
        }

        return res.size();
    }
};

int main() {
    auto *solution = new Solution();
    int n = 5;
//    vector<vector<char>> numIslands = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<vector<char>> numIslands = {{'1'}, {'1'}};
    solution->numIslands(numIslands);

}

