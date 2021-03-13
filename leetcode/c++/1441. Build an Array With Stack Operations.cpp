// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> buildArray(vector<int> &target, int n) {
        int size = target.size();
        stack<int> stk;
        vector <string> res;
        int j = 1;
        for (int i = 0; i < size; i++) {
            stk.push(j++);
            res.push_back("Push");
            while (stk.top() < target[i] && j <= n) {
                stk.pop();
                stk.push(j);
                res.push_back("Pop");
                res.push_back("Push");
                j++;
            }
            if (stk.top() == target[size - 1]) return res;
        }
        return res;
    }
};

// 简化栈
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector <string> buildArray(vector<int> &target, int n) {
        int size = target.size();
        stack<int> stk;
        vector <string> res;
        int j = 1;
        for (int i = 0; i < size; i++) {
            j++;
            res.push_back("Push");
            while (j - 1 < target[i] && j <= n) {
                res.push_back("Pop");
                res.push_back("Push");
                j++;
            }
        }
        return res;
    }
};