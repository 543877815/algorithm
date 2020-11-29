
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

bool compare(vector<int> &a, vector<int>&b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> record;
        int m = points.size();

        sort(points.begin(), points.end(), compare);

        int start = points[0][0], end = points[0][1];


        for (int i = 1; i < m; i++) {
            if (points[i][0] <= end) {
                end = points[i][1];
            } else {
                record.push_back({start, end});
                start = points[i][0];
                end = points[i][1];
            }
        }

        for (int i = 0; i < m; i++) {
            cout << points[i][0] << " " << points[i][1] << endl;
        }

        return record.size();
    }
};

int main() {
    auto *solution = new Solution();
    vector<vector<<int>> point = {{10,16},{2,8},{1,6},{7,12}};
    solution->findMinArrowShots(points);
}

