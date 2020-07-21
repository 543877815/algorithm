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


// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res = {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        while (left <= right) {
            if (nums[middle] > target) {
                right = middle - 1;
                middle = (left + right) / 2;
            } else if (nums[middle] < target) {
                left = middle + 1;
                middle = (left + right) / 2;
            } else {
                res[0] = middle;
                res[1] = middle;
                do {
                    middle--;
                } while (target == nums[middle] && middle > 0);
                res[0] = middle + 1;

                middle = res[1];
                do {
                    middle++;
                } while (target == nums[middle] && middle < nums.size());
                res[1] = middle - 1;
                break;
            }
        }
        return res;
    }
};


int main() {
    vector<int> a = {1};

    Solution c = Solution();
    c.searchRange(a, 1);
}