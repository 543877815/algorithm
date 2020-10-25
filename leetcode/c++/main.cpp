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
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T); // 我们记录以其为左端点的子区间中最远的右端点
        int last=0, ret=0, pre=0;
            for (vector<int> &it: clips) {
                if (it[0] < T) {
                    maxn[it[0]] = max(maxn[it[0]], it[1]);
                }
            }
            for (int i = 0; i < T; i++) {
                last = max(last, maxn[i]);
                if (i == last) return -1;
                if (i == pre) {
                    ret++;
                    pre = last;
                }
        }
        return ret;
    }
};

int main() {
    auto *solution = new Solution();
    vector<vector<int>> nums = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    solution->videoStitching(nums, 10);

}

