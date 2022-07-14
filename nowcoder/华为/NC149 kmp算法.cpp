// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算模板串S在文本串T中出现了多少次
     * @param S string字符串 模板串
     * @param T string字符串 文本串
     * @return int整型
     */
    int kmp(string S, string T) {
        // write code here
        int n = S.size(), m = T.size();
        vector<int> next(n, 0);  // next 表示与前缀最长的相同子串长度
        int len = 0;
        int i = 1;
        while (i < n) {
            if (S[len] == S[i]) {
                len++;
                next[i] = len;
                i++;
            } else {
                if (len == 0) {
                    i++;
                } else {
                    len = next[len - 1];  // 此处看更短的前后缀
                }
            }
        }

        int res = 0;
        i = 0; // 主串
        int j = 0;  // 子串
        while (i < m) {
            if (S[j] == T[i]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }

            if (j == n) {
                res++;
            }
        }

        return res;
    }
};