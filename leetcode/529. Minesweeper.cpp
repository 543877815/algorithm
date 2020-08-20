// 深度优先遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int d[8][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1},
            {1,  1},
            {1,  -1},
            {-1, 1},
            {-1, -1}
    };
    int m, n;
    vector <vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector <vector<char>> &board, int x, int y) {
        visited[x][y] = true;

        int Mine = 0;
        for (int i = 0; i < 8; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (isArea(newx, newy)) {
                if (board[newx][newy] == 'M') Mine++;
            }
        }

        if (Mine != 0) board[x][y] = Mine + '0';
        else {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    DFS(board, newx, newy);
                }
            }
        }
    }

public:
    vector <vector<char>> updateBoard(vector <vector<char>> &board, vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
        } else {
            m = board.size();
            n = board[0].size();
            visited = vector < vector < bool >> (m, vector<bool>(n, false));
            DFS(board, click[0], click[1]);
        }
        return board;
    }
};


// 广度优先遍历
// 时间复杂度：O(mn)
// 空间复杂度：O(mn)
class Solution {
private:
    int d[8][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1},
            {1,  1},
            {1,  -1},
            {-1, 1},
            {-1, -1}
    };
    int m, n;
    vector <vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector <vector<char>> updateBoard(vector <vector<char>> &board, vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        m = board.size();
        n = board[0].size();
        visited = vector < vector < bool >> (m, vector<bool>(n, false));
        queue <vector<int>> q;
        visited[click[0]][click[1]] = true;
        q.push(click);
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int Mine = 0;
            for (int i = 0; i < 8; i++) {
                int newx = curr[0] + d[i][0];
                int newy = curr[1] + d[i][1];
                if (isArea(newx, newy)) {
                    if (board[newx][newy] == 'M') Mine++;
                }
            }
            if (Mine != 0) board[curr[0]][curr[1]] = Mine + '0';
            else {
                board[curr[0]][curr[1]] = 'B';
                for (int i = 0; i < 8; i++) {
                    int newx = curr[0] + d[i][0];
                    int newy = curr[1] + d[i][1];
                    if (isArea(newx, newy) && !visited[newx][newy]) {
                        q.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
            }
        }
        return board;
    }
};