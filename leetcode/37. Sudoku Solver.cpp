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

using namespace std;

// 回溯
class Solution {
private:
    vector<vector<bool>> col, row, block, valid;
    int remain;

    void DFS(vector<vector<char>> &board, int &index) {
        if (remain == 0) return;
        int skip = 0;
        for (int i = index / 9; i < 9; i++) {  // 行
            for (int j = i == index / 9 ? index % 9 : 0; j < 9; j++) {  // 列
                if (board[i][j] == '.' && !valid[i][j]) {
                    // 尝试用 1 - 9 进行填数
                    for (int k = 0; k < 9; k++) {
                        int blockIndex = i / 3 * 3 + j / 3;
                        if (!row[i][k] && !col[j][k] && !block[blockIndex][k]) {
                            row[i][k] = true;
                            col[j][k] = true;
                            block[blockIndex][k] = true;
                            board[i][j] = (char) (k + 1 + '0');
                            index++;
                            remain--;
                            DFS(board, index);
                            if (remain == 0) return;
                            row[i][k] = false;
                            col[j][k] = false;
                            block[blockIndex][k] = false;
                            board[i][j] = '.';
                            remain++;
                            index--;
                        }
                    }
                    index -= skip;
                    return;
                } else {
                    skip++;
                    index++;
                }
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        block = vector<vector<bool>>(9, vector<bool>(9, false));
        valid = vector<vector<bool>>(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int blockIndex = i / 3 * 3 + j / 3;
                    row[i][index] = true;
                    col[j][index] = true;
                    block[blockIndex][index] = true;
                    valid[i][j] = true;
                } else {
                    remain++;
                }
            }
        }
        int index = 0;
        DFS(board, index);
        return;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<char >>
            d = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solution.solveSudoku(d);
}

