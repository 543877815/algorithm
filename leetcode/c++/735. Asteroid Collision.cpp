// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            int curr = asteroids[i];
            if (!sk.empty() && (sk.top() > 0 && curr <= 0)){
                while (!sk.empty() && (sk.top() > 0 && curr <= 0)) {
                    if (abs(curr) == abs(sk.top())) {
                        sk.pop();
                        curr = 1;  // 退出循环
                    } else if (abs(curr) > abs(sk.top())) {
                        sk.pop();
                    } else {
                        curr = 1;  // 退出循环
                    }
                }
                if (curr <= 0) sk.push(curr);
            } else {
                sk.push(curr);
            }
        }
        vector<int> res = vector<int>(sk.size());
        for (int i = sk.size() - 1; i >= 0; i--) {
            res[i] = sk.top();
            sk.pop();
        }
        return res;
    }
};