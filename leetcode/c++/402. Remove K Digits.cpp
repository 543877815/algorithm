// 栈和贪心
// 空间复杂度：O(n)
// 时间复杂度：O(n）
class Solution {
public:
    string removeKdigits(string num, int k) {
        int m = num.size();
        stack<char> increase;
        stack<char> decrease;

        for (int i = m - 1; i >= 0; i--) {
            increase.push(num[i]);
        }

        while (k > 0 && !increase.empty()) {
            char tmp = increase.top();
            increase.pop();
            if (!increase.empty() && tmp > increase.top()) {
                k--;
                if (!decrease.empty()) {
                    increase.push(decrease.top());
                    decrease.pop();
                }
            } else {
                decrease.push(tmp);
            }
        }
        string res;
        while (k > 0 && !decrease.empty()) {
            decrease.pop();
            k--;
        }

        while (!decrease.empty()) {
            increase.push(decrease.top());
            decrease.pop();
        }

        bool zero = true;
        while (!increase.empty()) {
            if (zero && increase.top() == '0') {
            } else {
                zero = false;
                res.push_back(increase.top());
            }
            increase.pop();
        }

        return (res.empty()) ? "0" : res;
    }
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        int m = num.size();
        vector<char> stk;
        for (int i = 0; i < m; i++) {
            if (!stk.empty() && k > 0 && stk.back() > num[i]) {
                stk.pop_back();
                k--;
                i--;
            } else {
                stk.push_back(num[i]);
            }
        }

        while (k > 0) {
            k--;
            stk.pop_back();
        }

        string res;
        bool zero = true;
        for (char i : stk) {
            if (zero && i == '0');
            else {
                zero = false;
                res.push_back(i);
            }
        }

        return res.empty() ? "0" : res;
    }
};
