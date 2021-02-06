// 滑动窗口
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
        int n = big.size(), m = small.size();
        unordered_map<int, int> freq_t, freq_s;
        for (int i = 0; i < m; i++) {
            freq_t[small[i]]++;
            freq_s[small[i]] = 0;
        }
        int minLeft = 0, minRight = 0;
        int left = 0, right = 0, minDis = n + 1, count = m;
        while (right < n && left < n) {
            if (count > 0) {
                if (freq_t.count(big[right]) != 0) {
                    if (freq_s[big[right]] < freq_t[big[right]]) count--;
                    freq_s[big[right]]++;
                }
                right++;
            } else {
                if (freq_t.count(big[left]) != 0) {
                    if (freq_s[big[left]] <= freq_t[big[left]]) count++;
                    freq_s[big[left]]--;
                }
                left++;
            }
            if (count == 0 && minDis > right - left - 1) {
                minRight = right - 1;
                minLeft = left;
                minDis = right - left - 1;
            }
        }

        unordered_map<int, int> tmp;
        for (int i = minLeft; i < minRight; i++) {
            if (freq_t.count(big[i]) != 0)
                tmp[big[i]]++;
        }
        while (minLeft < n) {
            if (freq_t.count(big[minLeft]) == 0) minLeft++;
            else {
                if (tmp[big[minLeft]] > freq_t[big[minLeft]]) {
                    tmp[big[minLeft]]--;
                    minLeft++;
                } else break;
            }
        }

        return minDis == n + 1 ? vector < int > {} : vector < int > {minLeft, minRight};
    }
};