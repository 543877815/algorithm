// 贪心+栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> visited(26, false);
        vector<int> lastIndex(26, -1);
        stack<char> sk;
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            if (visited[s[i] - 'a']) continue;
            while (!sk.empty() && sk.top() > s[i] && lastIndex[sk.top() - 'a'] > i) {
                visited[sk.top() - 'a'] = false;
                sk.pop();
            }
            sk.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string res;
        while (!sk.empty()) {
            res = sk.top() + res;
            sk.pop();
        }
        return res;
    }
};