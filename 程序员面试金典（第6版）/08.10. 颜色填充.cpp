// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    const int dp[4][2] = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1}
    };
    int m, n;
    vector <vector<int>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector <vector<int>> &image, int x, int y, int oldColor, int newColor) {
        image[x][y] = newColor;
        for (int i = 0; i < 4; i++) {
            int newx = x + dp[i][0];
            int newy = y + dp[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && image[newx][newy] == oldColor) {
                visited[newx][newy] = true;
                DFS(image, newx, newy, oldColor, newColor);
            }
        }
    }

public:
    vector <vector<int>> floodFill(vector <vector<int>> &image, int sr, int sc, int newColor) {
        m = image.size();
        if (m == 0) return image;
        n = image[0].size();
        if (n == 0) return image;
        visited = vector < vector < int >> (m, vector<int>(n, false));
        DFS(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};