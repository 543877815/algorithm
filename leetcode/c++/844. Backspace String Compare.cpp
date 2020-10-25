// 使用栈
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> S_s;
        stack<char> T_s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '#') {
                if (!S_s.empty()) S_s.pop();
            } else {
                S_s.push(S[i]);
            }
        }

        for (int j = 0; j < T.size(); j++) {
            if (T[j] == '#') {
                if (!T_s.empty()) T_s.pop();
            } else {
                T_s.push(T[j]);
            }
        }

        while (!S_s.empty() && !T_s.empty()) {
            char s = S_s.top();
            S_s.pop();
            char t = T_s.top();
            T_s.pop();
            if (s != t) return false;
        }

        return S_s.empty() && T_s.empty();
    }
};

// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m = S.size(), n = T.size();
        int i = m - 1, j = n - 1, tmp = 0;
        while (i >= 0 && j >= 0) {
            while (i >= 0 && j >= 0 && S[i] == T[j] && S[i] != '#') {
                i--;
                j--;
            }
            while (i >= 0 && S[i] == '#') {
                tmp++;
                i--;
            }
            while (i >= 0 && tmp > 0) {
                if (S[i] != '#') tmp--;
                else tmp++;
                i--;
            }
            while (j >= 0 && T[j] == '#') {
                tmp++;
                j--;
            }
            while (j >= 0 && tmp > 0) {
                if (T[j] != '#') tmp--;
                else tmp++;
                j--;
            }

            if (i >= 0 && j >= 0 && S[i] != '#' && T[j] != '#' && S[i] != T[j]) return false;
        }

        tmp = 0;
        while (i >= 0) {
            while (i >= 0 && S[i] == '#') {
                tmp++;
                i--;
            }
            while (i >= 0 && tmp > 0) {
                if (S[i] != '#') tmp--;
                else tmp++;
                i--;
            }
            if (i >= 0 && S[i] != '#') break;
        }

        tmp = 0;
        while (j >= 0) {
            while (j >= 0 && T[j] == '#') {
                tmp++;
                j--;
            }
            while (j >= 0 && tmp > 0) {
                if (T[j] != '#') tmp--;
                else tmp++;
                j--;
            }
            if (j >= 0 && T[j] != '#') break;
        }

        return i < 0 && j < 0;
    }
};