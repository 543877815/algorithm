// 回溯，深度优先搜索
// 时间复杂度：O(n*m*n*m)
// 时间复杂度：O(nm)
class Solution {
private:
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};
    int m, n;
    vector <vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从board[startx][starty]开始,寻找word[index...word.size()]
    bool searchWord(const vector <vector<char>> &board, const string &word, int index, int startx, int starty) {
        if (index == word.size() - 1)
            return board[startx][starty] == word[index];

        if (board[startx][starty] == word[index]) {
            visited[startx][starty] = true;
            // 从[startx][starty]出发,向四个方向寻找
            for (int i = 0; i < 4; i++) {
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if (inArea(newx, newy) && !visited[newx][newy] && searchWord(board, word, index + 1, newx, newy))
                    return true;
            }
            visited[startx][starty] = false;
        }

        return false;
    }

public:
    bool exist(vector <vector<char>> &board, strim = board.size();
    n = board[0].size();
    visited = vector < vector < bool >> (m, vector<bool>(n, false));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (searchWord(board, word, 0, i, j)) return true;
        }
    }ng word) {


        return false;
    }
};