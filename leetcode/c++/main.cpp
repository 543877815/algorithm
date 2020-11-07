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
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        // 插入有序数组
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i+1][0]) {
                    intervals.insert(intervals.begin() + i + 1, newInterval);
                }
            }
        }
        if (intervals.size() == n) {
            if (intervals.empty()) intervals.push_back(newInterval);
            else if (newInterval[0] >= intervals.back()[0]) intervals.push_back(newInterval);
            else (intervals.insert(intervals.begin(), newInterval));
        }


        // 合并
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (i != n - 1 && intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                if (intervals[i][1] >= intervals[i+1][1]) {
                    intervals[i+1][1] = intervals[i][1];
                }
            } else {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;
    }
};
int main() {
    auto *solution = new Solution();
    vector<vector<int>> intervals = {{2,3},{5,5},{6,6},{7,7},{8,11}};
    vector<int> newInterval = {6,13};
    solution->insert(intervals, newInterval);

}

