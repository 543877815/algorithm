// 栈+贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string removeDuplicates(string S) {
        stack<int> sk;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (sk.empty() || sk.top() != S[i]) {
                sk.push(S[i]);
            } else {
                sk.pop();
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

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (int i = 0; i < S.size(); i++) {
            if (res.empty() || res.back() != S[i]) {
                res.push_back(S[i]);
            } else {
                res.pop_back()
            }
        }
        return res;
    }
};