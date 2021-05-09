
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        set<int> st(bloomDay.begin(), bloomDay.end()); // set 去重
        vector<int> vt(st.begin(), st.end()); // 方便遍历
        int left = 0, right = vt.size() - 1;
        int res = INT_MAX;
        while (left <= right) {
            int middle = (right + left) / 2;
            int day = vt[middle];
            int count = 0, bunch = 0;
            for (int i = 0; i < n; i++) {
                if (day >= bloomDay[i]) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= k && count % k == 0) {
                    bunch++;
                    if (bunch == m) {
                        res = min(res, day);
                    }
                }
            }
            if (day == res) right = middle - 1;
            else left = middle + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    auto *solution = new Solution();
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    TreeNode *six = new TreeNode(6);

    one->right = two;
    one->left = three;
    two->right = six;
    three->right = four;
    three->left = five;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    solution->minDays(bloomDay, 3, 1);

}


>>>>>>> b801056e9539e613ca67d58ab749c4bb5ac53cfb
