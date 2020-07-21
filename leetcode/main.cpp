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

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int upper_bound = target / 2 + 1;
        int lower_bound = 1;
        int left = 0, right = 0, sum = 0;
        vector<vector<int>> res;
        vector<int> list;
        while (left <= right && left <= upper_bound) {
            while(sum<target) {
                sum+=right;
                list.push_back(right);
                right++;
            }
            if (sum == target) res.push_back(list);
            sum-=left;
            list.erase(list.begin(), list.begin()+1);
            left++;
        }
        return res;
    }
};

int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 9};

    Solution c = Solution();
    c.findContinuousSequence(9);
}