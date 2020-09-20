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

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathname;
        string record, res;
        for (int i = 1; i <= path.size(); i++) {
            record += path[i - 1];
            if (i == path.size() || path[i] == '/') {
                if (record == "/..") {
                    if (pathname.size()) pathname.pop();
                } else if (record != "/." && record != "/") {
                    pathname.push(record);
                }
                record = "";
            }
        }
        while (!pathname.empty()) {
            res = pathname.top() + res;
            pathname.pop();
        }
        int a = 0;
        return res == "" ? "/" : res;
    }
};

/**
 * "/..hidden"
 * "/..."
 * "/abc..."
 */
int main() {
    string a = "/abc...";

    Solution c = Solution();
    c.simplifyPath(a);
}