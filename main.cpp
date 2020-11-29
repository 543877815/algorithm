
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <cmath>
#include <queue>
#include <cassert>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool compare(vector<int> &a, vector<int>&b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int m = points.size();
        sort(points.begin(), points.end(), compare);
        int end = points[0][1];
        int lastIndex = 0;
        int res = 0;
        for (int i = 1; i < m; i++) {
            if (points[i][0] > end) {
                res ++;
                lastIndex = i;
                end = points[i][1];
            }
        }
        res += m - lastIndex;
        return res;
    }
};

int main() {
    auto *solution = new Solution();
    vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    solution->findMinArrowShots(points);
}

