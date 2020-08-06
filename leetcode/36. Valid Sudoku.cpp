// 一次遍历
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
private:
    vector<vector<bool>> col, row, block;
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        block = vector<vector<bool>>(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int blockIndex = i / 3 * 3 + j / 3;
                    if (row[i][index] || col[j][index] || block[blockIndex][index]) return false;
                    row[i][index] = true;
                    col[j][index] = true;
                    block[blockIndex][index] = true;
                }
            }
        }
        return true;
    }
};

