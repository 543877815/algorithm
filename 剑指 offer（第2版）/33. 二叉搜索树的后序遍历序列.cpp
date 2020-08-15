// 递归分治
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    bool verify(vector<int> &postorder, int start, int end) {
        if (postorder.empty() || start >= end) return true;
        int i = start;
        while (postorder[i] < postorder[end]) i++;
        int j = i;
        while (postorder[i] > postorder[end]) i++;
        return i == end && verify(postorder, start, j - 1) && verify(postorder, j, end - 1);
    }

    bool verifyPostorder(vector<int> &postorder) {
        int n = postorder.size();
        return verify(postorder, 0, n - 1);
    }
};

// 辅助栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        stack<int> s;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root) return false;
            while (!s.empty() && s.top() > postorder[i]) {
                root = s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
};