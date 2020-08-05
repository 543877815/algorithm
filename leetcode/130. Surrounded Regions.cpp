// 深度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int n, m;
    vector <vector<bool>> visited;
    int d[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};

    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void DFS(vector <vector<char>> &board, int x, int y) {
        visited[x][y] = true;
        if (board[x][y] == 'O') {
            for (int i = 0; i < 4; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (isArea(newx, newy) && !visited[newx][newy] && board[newx][newy] == 'O')
                    DFS(board, newx, newy);
            }
        }
    }

public:
    void solve(vector <vector<char>> &board) {
        n = board.size();
        if (n <= 2) return;
        m = board[0].size();
        if (m <= 2) return;
        visited = vector < vector < bool >> (n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            if (!visited[i][0]) {
                DFS(board, i, 0);
            }
            if (!visited[i][m - 1]) {
                DFS(board, i, m - 1);
            }
        }

        for (int i = 0; i < m; i++) {
            if (!visited[0][i]) {
                DFS(board, 0, i);
            }
            if (!visited[n - 1][i]) {
                DFS(board, n - 1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};