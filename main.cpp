
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
    bool wordPattern(string pattern, string s) {
        if (s.find(' ') == -1) return s == pattern;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        string tmp;
        for (auto &x : pattern) {
            int index = s.find(' ');
            if (index != -1) {
                tmp = s.substr(0, index);
                s = s.substr(index+1);
                if (s2p.count(tmp) == 0) s2p[tmp] = x;
                else if (s2p[tmp] != x) return false;
                if (p2s.count(x) == 0) p2s[x] = tmp;
                else if (p2s[x] != tmp) return false;
            } else if (p2s.count(x) != 0 && p2s[x] != s) return false;
        }

        return true;
    }
};

int main() {
    auto *solution = new Solution();
    string pattern ="abc", str = "a b c";
    solution->wordPattern(pattern, str);

}

