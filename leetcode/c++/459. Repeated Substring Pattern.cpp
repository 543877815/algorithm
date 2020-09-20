class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
    }
};


// KMP
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    bool kmp(const string &query, const string &pattern) {
        int n = query.size();
        int m = pattern.size();
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        int match = -1;
        for (int i = 1; i < n - 1; ++i) {
            while (match != -1 && pattern[match + 1] != query[i]) {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) {
                ++match;
                if (match == m - 1) {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s + s, s);
    }
};


// version 2
class Solution {
public:
    // char:  a b a b a b c a
    // index: 0 1 2 3 4 5 6 7
    // pmt:   0 0 1 2 3 4 0 1   字符串前后缀中匹配最大长度
    // next: -1 0 0 1 2 3 4 0   pmt矩阵右移一位，值的含义，匹配失败时，重新开始匹配的索引。
    //                          其记录着上一段拥有相同序列特征的位置。
    bool kmp(const string &query, const string &pattern) {
        // 构建next数组
        int n = query.size();
        int m = pattern.size();
        vector<int> next(m, -1);
        int j = 0, i = -1;
        while (j < m - 1) {
            if (i == -1 || pattern[j] == pattern[i])
                next[++j] = ++i;
            else
                i = next[i];
        }

        // 匹配
        i = 0;  // 主串位置
        j = 0;  // 模式串位置
        while (i < n && j < m) {
            if (j == -1 || query[i] == pattern[j]) { // 当j为-1时，要移动的是i，当然j也要归零
                i++;
                j++;
            } else {
                j = next[j]; // j回溯
            }
        }

        // 匹配成功
        if (j == pattern.size()) return true;
        else return false;

    }

    bool repeatedSubstringPattern(string s) {
        return kmp((s + s).substr(1, s.size() * 2 - 2), s);
    }
};