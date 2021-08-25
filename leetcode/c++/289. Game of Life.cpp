// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void gameOfLife(vector <vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();
        int direction[8][2]{
                {1,  0},
                {1,  1},
                {0,  1},
                {-1, 1},
                {-1, 0},
                {-1, -1},
                {0,  -1},
                {1,  -1}
        };
        vector <vector<int>> lives = vector < vector < int >> (n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    for (int k = 0; k < 8; k++) {
                        int newx = direction[k][0] + i;
                        int newy = direction[k][1] + j;
                        if (isArea(newx, newy, n, m)) {
                            lives[newx][newy]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    if (lives[i][j] < 2) board[i][j] = 0;
                    else if (lives[i][j] == 2 || lives[i][j] == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                } else {
                    if (lives[i][j] == 3) board[i][j] = 1;
                }
            }
        }
    }
};

// 空间优化
// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void gameOfLife(vector <vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();
        int directions[8][2] = {
                {1,  0},
                {1,  1},
                {0,  1},
                {-1, 1},
                {-1, 0},
                {-1, -1},
                {0,  -1},
                {1,  -1}
        };
        // 死->死：0
        // 活->活：1
        // 活->死：2
        // 死->活：3
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int lives = 0;
                for (int k = 0; k < 8; k++) {
                    int newx = i + directions[k][0];
                    int newy = j + directions[k][1];
                    if (isArea(newx, newy, n, m) && (board[newx][newy] == 1 || board[newx][newy] == 2)) {
                        lives++;
                    }
                }
                if (board[i][j] == 0) {
                    if (lives == 3) board[i][j] = 3;
                    else board[i][j] = 0;
                } else {
                    if (lives < 2 || lives > 3) board[i][j] = 2;
                    else board[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = (board[i][j] == 1 || board[i][j] == 3) ? 1 : 0;
            }
        }
    }
};