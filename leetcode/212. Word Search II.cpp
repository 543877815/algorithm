// 参考79，结果超时
// 优化：前缀树，参考208
class Solution {
private:
    vector <string> res;
    bool result;
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
        if (index == word.size() - 1) {
            if (board[startx][starty] == word[index]) {
                res.push_back(word);
                return true;
            } else {
                return false;
            }
        }

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
    vector <string> findWords(vector <vector<char>> &board, vector <string> &words) {
        m = board.size();
        n = board[0].size();

        for (string word :words) {
            result = false;
            visited = vector < vector < bool >> (m, vector<bool>(n, false));
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    result = searchWord(board, word, 0, i, j);
                    if (result) break;
                }
                if (result) break;
            }
        }
        return res;
    }
};