
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

bool compare(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> on_stack(26, false);
        vector<int> last(26, -1);
        stack<int> sk;
        int n = s.size();
        // 记录最后一次出现的位置
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            if (on_stack[s[i] - 'a']) continue;
            if (sk.empty() || last[s[i] - 'a'] == i) {
                sk.push(s[i]);
                on_stack[s[i] - 'a'] = true;
            } else if (s[i] < sk.top() && last[s[i] - 'a'] != i) {
                on_stack[sk.top()] = false;
                sk.pop();
                sk.push(s[i]);
                on_stack[s[i]] = true;
            }
        }
        string res;
        while (!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();
    string input = "cdadabcc";
    solution->removeDuplicateLetters(input);

}

