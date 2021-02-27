// 滑动窗口
// 时间复杂度：O(26N+26^2)
// 空间复杂度：O(26)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int n = s.size();
        // 遍历字符集的种类
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            vector<int> record(26, 0);
            int total = 0, less = 0;
            while (r < n) {
                int r_index = s[r] - 'a';
                record[r_index]++;
                if (record[r_index] == 1) {
                    total++;
                    less++;
                }
                if (record[r_index] == k) {
                    less--;
                }
                while (total > t) {
                    int l_index = s[l] - 'a';
                    record[l_index]--;
                    if (record[l_index] == 0) {
                        total--;
                        less--;
                    }
                    if (record[l_index] == k - 1) {
                        less++;
                    }
                    l++;
                }
                if (less == 0) res = max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};

// 分治
// 时间复杂度：O(26n)
// 空间复杂度：O(26^2)
class Solution {
public:
    int dfs(const string &s, int l, int r, int k) {
        vector<int> record(26, 0);
        for (int i = l; i <= r; i++) {
            record[s[i] - 'a']++;
        }
        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (record[i] > 0 && record[i] < k) {
                split = i + 'a';
                break;
            }
        }

        // 如果不存在分割点则满足返回条件
        if (split == 0) return r - l + 1;

        int i = l;
        int res = 0;
        while (i <= r) {
            // 否则找到一个分割点
            while (i <= r && s[i] == split) i++;
            if (i > r) break;
            int start = i;
            // 从该分割点开始贪婪地找最大长度
            while (i <= r && s[i] != split) i++;
            int length = dfs(s, start, i - 1, k);
            res = max(res, length);
        }

        return res;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        return dfs(s, 0, n - 1, k);
    }
};