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

using namespace std;


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) break;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (target == matrix[i][j]) return true;
                if (matrix[i][j] > target) break;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> a = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };

    Solution c = Solution();
    c.findNumberIn2DArray(a, 5);
}