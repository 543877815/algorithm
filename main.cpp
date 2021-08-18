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
    vector<int> countBits(int n) {
        vector<int> res = {0};
        int index = 1;
        while (index <= n) {
            int m = res.size();
            for (int i = 0; i < m && res.size() <= n; i++) {
                res.push_back(res[i] + 1);
            }
            index *= 2;
        }

        return res;
    }
};

int main() {
    auto *solution = new Solution();
    TreeNode *five1 = new TreeNode(5);
    TreeNode *eight = new TreeNode(8);
    TreeNode *five2 = new TreeNode(5);

    vector<int> a = {1, 2, 3, 4};
    solution->countBits(2);
}
