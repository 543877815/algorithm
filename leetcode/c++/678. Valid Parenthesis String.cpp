// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> left;
        stack<char> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else return false;
            }
        }
        while (!star.empty() && !left.empty()) {
            int starIndex = star.top();
            star.pop();
            int leftIndex = left.top();
            left.pop();
            if (starIndex < leftIndex) return false;
        }
        return left.empty();
    }
};