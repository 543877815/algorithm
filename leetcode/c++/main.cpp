
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
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int m, n;
    int dp[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
    };
    queue<pair<int, int>> q;
    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
public:
<<<<<<< HEAD
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int m = people.size();
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(2));
        sort(people.begin(), people.end(), [&](vector<int> &x, vector<int> &y) {
            if (x[0] != y[0]) return x[0] < y[0];
            else return x[1] > y[1];
        });

        /*for (int i = 0; i < m; i++) {
            cout << people[i][0] << " " << people[i][1] << endl;
        }*/

        vector<bool> used = vector<bool>(m, false);

        for (int i = 0; i < m; i++) {
            int idx = people[i][1];
            int j = 0;

            while ((idx > 0 && j < m) || used[j]) {
                if (!used[j]) {
                    idx--;
                }
                j++;
            }

            if (j < m) {
                used[j] = true;
                res[j] = people[i];
=======
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));
        res.push_back({r0, c0});
        visited[r0][c0] = true;
        m = R;
        n = C;
        q.push({r0, c0});
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dp[i][0];
                int newy = y + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    q.push({newx, newy});
                    res.push_back({newx, newy});
                }
>>>>>>> 215b63fa3215c1b975e3159d8d1200114bffd9e3
            }
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();
<<<<<<< HEAD
    vector<vector<int>> array = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    solution->reconstructQueue(array);
=======
    solution->allCellsDistOrder(2, 3, 1, 2);

>>>>>>> 215b63fa3215c1b975e3159d8d1200114bffd9e3
}

