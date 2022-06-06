// 哈希表、双指针移动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param S string字符串
     * @param T string字符串
     * @return string字符串
     */
    vector<int> map_S;
    vector<int> map_T;

    int getIndex(string &S, int i) {
        return islower(S[i]) ? S[i] - 'a' : (S[i] - 'A') + 26;
    }

    bool isValid() {
        int valid = true;
        for (int i = 0; i < 52; i++) {
            if (map_S[i] < map_T[i]) {
                valid = false;
                break;
            }
        }
        return valid;
    }

    string minWindow(string S, string T) {
        // write code here
        map_S = vector<int>(52, 0);
        map_T = vector<int>(52, 0);
        int n = S.size(), m = T.size();
        if (n < m) return "";
        // 构建hash表
        for (int i = 0; i < n; i++) {
            int index = getIndex(S, i);
            map_S[index]++;
        }
        for (int i = 0; i < m; i++) {
            int index = getIndex(T, i);
            map_T[index]++;
        }

        // 检查是否存在最短子串
        for (int i = 0; i < 52; i++) {
            if (map_S[i] < map_T[i]) return "";
            map_S[i] = 0; // 重新初始化
        }

        // 滑动窗口
        int left = 0, right = 0;
        int minLeft = 0, minRight = n;

        for (; right < m; right++) {
            int index = getIndex(S, right);
            map_S[index]++;
        }

        if (isValid()) return T;

        int index = -1;
        while (right < n) {
            index = islower(S[right]) ? S[right] - 'a' : (S[right] - 'A') + 26;
            map_S[index]++;
            right++;
            // 检查窗口是否满足
            while (left < right && isValid()) {
                if (minRight - minLeft > right - left) {
                    minRight = right;
                    minLeft = left;
                }
                index = islower(S[left]) ? S[left] - 'a' : (S[left] - 'A') + 26;
                map_S[index]--;
                left++;
            }
        }

        return S.substr(minLeft, minRight - minLeft);
    }
};