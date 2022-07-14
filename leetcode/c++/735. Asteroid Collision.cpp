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

// 20220713
// 栈
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            if (sk.empty()) {
                sk.push(asteroids[i]);
            } else if (sk.top() * asteroids[i] > 0) { // 同号
                sk.push(asteroids[i]);
            } else if (sk.top() > 0 && asteroids[i] < 0){  // 不同号，且碰撞
                if (abs(sk.top()) > abs(asteroids[i])) continue;  // 大于
                else if (abs(sk.top()) == abs(asteroids[i])) sk.pop(); // 相同则爆炸
                else {  // 小于
                    while (!sk.empty() && sk.top() > 0 && abs(sk.top()) < abs(asteroids[i])) {
                        sk.pop();
                    }
                    if (!sk.empty() && sk.top() > 0 && abs(sk.top()) == abs(asteroids[i])) sk.pop();
                    else if (sk.empty() || sk.top() < 0) sk.push(asteroids[i]);
                }
            } else if (sk.top() < 0 && asteroids[i] > 0) {  // 不同号，但不碰撞
                sk.push(asteroids[i]);
            }
        }

        vector<int> res;
        while (!sk.empty()) {
            res.push_back(sk.top());
            sk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};