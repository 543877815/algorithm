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
    string removeKdigits(string num, int k) {
        int m = num.size();
        vector<char> stk;
        for (int i = 0; i < m; i++) {
            if (!stk.empty() && k > 0 && stk.back() > num[i]) {
                stk.pop_back();
                k--;
                i--;
            } else {
                stk.push_back(num[i]);
            }
        }

        while (k > 0) {
            k--;
            stk.pop_back();
        }

        string res;
        bool zero = true;
        for (char i : stk) {
            if (zero && i == '0');
            else {
                zero = false;
                res.push_back(i);
            }
        }

        return res.empty() ? "0" : res;
    }
};

int main() {
    auto *solution = new Solution();
    solution->removeKdigits("123456432", 4);

}

