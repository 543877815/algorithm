// 回溯
// 时间复杂度：O(n!)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */

    /** 
        0 1 2 3
      0 # # # #
      1 # # # #
      2 # # # #
      3 # # # # 
    **/
    vector<bool> columns;
    vector<bool> rows;
    vector<bool> up;
    vector<bool> down;

    int res = 0;

    bool isArea(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    void dfs(int row, int n) {
        if (n == row) {
            res++;
            return;
        }
        // 遍历列
        for (int j = 0; j < n; j++) {
            int new_x = row;
            int new_y = j;
            if (isArea(new_x, new_y, n) && !rows[new_x] && !columns[new_y] && !down[(n - 1 - new_x) + (new_y)] &&
                !up[new_x + new_y]) {
                rows[new_x] = true;
                columns[new_y] = true;
                down[(n - 1 - new_x) + (new_y)] = true;
                up[new_x + new_y] = true;
                dfs(row + 1, n);
                rows[new_x] = false;
                columns[new_y] = false;
                down[(n - 1 - new_x) + (new_y)] = false;
                up[new_x + new_y] = false;
            }
        }
    }

    int Nqueen(int n) {
        // write code here
        columns = vector<bool>(n, false);
        rows = vector<bool>(n, false);
        up = vector<bool>(2 * n - 1, false);
        down = vector<bool>(2 * n - 1, false);
        int i = 0;
        // 在第0行，第j列
        for (int j = 0; j < n; j++) {
            rows[i] = true;
            columns[j] = true;
            down[(n - 1 - i) + (j)] = true;
            up[i + j] = true;
            dfs(1, n);
            rows[i] = false;
            columns[j] = false;
            down[(n - 1 - i) + (j)] = false;
            up[i + j] = false;
        }
        return res;
    }
};