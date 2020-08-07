// 时间复杂度：O(mn)
// 空间复杂度：O(mn)
class Solution {
private:
    int d[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
    int row, col;
    int res = 0;
    vector <vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < row && y < col;
    }

    int getSum(int num) {
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }

    void DFS(int x, int y, int k) {
        visited[x][y] = true;
        if (getSum(x) + getSum(y) <= k) res++;
        else return;
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && getSum(newx) + getSum(newy) <= k) {
                DFS(newx, newy, k);
            }
        }
    }

public:

    int movingCount(int m, int n, int k) {
        row = m;
        col = n;
        visited = vector < vector < bool >> (m, vector<bool>(n, false));
        DFS(0, 0, k);
        return res;
    }
};