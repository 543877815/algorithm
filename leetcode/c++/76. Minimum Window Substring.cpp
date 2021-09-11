// 时间复杂度：最坏情况下左右指针对 s 的每个元素各遍历一遍，哈希表中对 s 中
// 的每个元素各插入、删除一次，对 t 中的元素各插入一次。每次检查是否可行会遍
// 历整个 t 的哈希表，哈希表的大小与字符集的大小有关，设字符集大小为 C，则渐
// 进时间复杂度为 O(C|s|+|t|)
// 空间复杂度：这里用了两张哈希表作为辅助空间，每张哈希表最多不会存放超过字
// 符集大小的键值对，我们设字符集大小为 C ，则渐进空间复杂度为 O(C)。

class Solution {
private:
    vector<int> freq_s;
    vector<int> freq_t;

public:
    Solution() : freq_s(vector(58, 0)), freq_t(vector(58, 0)) {}

    bool check() {
        for (int i = 0; i < freq_s.size(); i++) {
            if (freq_s[i] < freq_t[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int left = 0, right = 0, res_left = 0, res_right = s.size() + 1;
        for (auto &c : t) {
            freq_t[c - 'A']++;
        }
        while (right < s.size()) {
            freq_s[s[right] - 'A']++;
            while (right - left + 1 >= t.size() && check()) {
                freq_s[s[left] - 'A']--;
                if (right - left < res_right - res_left) {
                    res_left = left;
                    res_right = right;
                }
                left++;
            }
            right++;
        }
        string res;
        if (res_right == s.size() + 1) {
            res = "";
        } else {
            res = s.substr(res_left, res_right - res_left + 1);
        }
        return res;
    }
};