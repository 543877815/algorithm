int strStr(char *haystack, char *needle) {
    int i = 0, j = 0, t = i;
    while (haystack[i] && needle[j]) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            continue;
        } else {
            t = t + 1;
            i = t;
            j = 0;
        }
    }
    if (needle[j] == '\0')
        return t;
    return -1;
}


// KMP
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next(m, -1);
        int j = 0, i = -1;
        while (j < m - 1) {
            if (i == -1 || needle[i] == needle[j]) {
                next[++j] = ++i;
            } else {
                i = next[i];
            }
        }

        i = 0;
        j = 0;
        while (i < n && j < m) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == m) return i - j;
        else return -1;
    }
};


// version 2
class Solution {
public:
    string shortestPalindrome(string s) {
        int m = s.size();
        // 构建 next 数组
        vector<int> next(m, -1);
        int j = 0, i = -1;
        while (j < m - 1) {
            if (i == -1 || s[j] == s[i])
                next[++j] = ++i;
            else
                i = next[i];
        }

        // 逆序匹配
        i = m - 1; // 主串位置
        j = 0; // 模式串位置
        while (i >= 0 && j < m) {
            if (j == -1 || s[i] == s[j]) {
                i--;
                j++;
            } else {
                j = next[j];
            }
        }
        string add = (j == m ? "" : s.substr(j, m));
        reverse(add.begin(), add.end());
        return add + s;
    }
};