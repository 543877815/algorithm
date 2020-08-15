// 深度优先遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
    vector <vector<int>> visited;
    int m, n;

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector <vector<int>> &image, int sr, int sc, const int oldColor, const int newColor) {
        visited[sr][sc] = true;
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            for (int i = 0; i < 4; i++) {
                int newx = sr + dp[i][0];
                int newy = sc + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    DFS(image, newx, newy, oldColor, newColor);
                }
            }
        }
    }

public:
    vector <vector<int>> floodFill(vector <vector<int>> &image, int sr, int sc, int newColor) {
        m = image.size();
        if (m == 0) return image;
        n = image[0].size();
        visited = vector < vector < int >> (m, vector<int>(n, false));
        DFS(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};