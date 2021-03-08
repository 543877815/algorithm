// 用131的函数，回溯/超时
// 时间复杂度：O(n*2^n)
// 空间复杂度：O(n^n)
class Solution {
private:
    vector <vector<string>> res;
public:
    int minCut(string s) {
        partition(s);
        int ret = INT_MAX;
        for (int i = 0; i < res.size(); i++) {
            int size = res[i].size() - 1;
            ret = min(ret, size);
        }
        return ret;
    }

    bool isPalindrome(const string &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }

    void DFS(const string &s, int begin, vector <string> &tmp) {
        if (s.size() == begin) {
            res.push_back(tmp);
            return;
        }
        for (int i = 1; i + begin <= s.size(); i++) {
            string substring = s.substr(begin, i);
            if (!substring.empty() && isPalindrome(substring)) {
                tmp.push_back(substring);
                DFS(s, i + begin, tmp);
                tmp.pop_back();
            }
        }

    }

    vector <vector<string>> partition(string s) {
        if (s.empty()) return res;
        vector <string> tmp;
        DFS(s, 0, tmp);
        return res;
    }
};

// 动态规划
// 设f(i)为前缀s[0,..i-1]中最小的分割的值
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector <vector<bool>> g(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (g[0][i]) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (g[j + 1][i]) {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }

        return f[n - 1];
    }
};