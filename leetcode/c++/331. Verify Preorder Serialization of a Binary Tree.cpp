// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        stack<int> stk;
        int i = 0;
        stk.push(1);
        while (i < n) {
            if (stk.empty()) return false;
            if (preorder[i] == ',') i++;
            else if (preorder[i] == '#') {
                stk.top() -= 1;
                if (stk.top() == 0) stk.pop();
                i++;
            } else {
                // 读取一个数字
                while (i < n && isdigit(preorder[i])) i++;
                stk.top() -= 1;
                if (stk.top() == 0) stk.pop();
                stk.push(2);
            }
        }
        return stk.empty();
    }
};

// 优化栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int num = 1;
        int i = 0;
        while (i < n) {
            if (num == 0) return false;
            if (preorder[i] == ',') i++;
            else if (preorder[i] == '#') {
                num--;
                i++;
            } else {
                while (i < n && isdigit(preorder[i])) i++;
                num++;
            }
        }

        return num == 0;
    }
};