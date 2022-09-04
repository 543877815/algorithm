// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isValid(vector<int> &cnt) {
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > 1) return false;
        }
        return true;
    }

    int longestNiceSubarray(vector<int> &nums) {
        int n = nums.size();
        int res = 1;

        int left = 0, right = 0;
        vector<int> cnt(32, 0);
        while (right < n) {
            int num;
            int idx;

            num = nums[right];
            idx = 0;
            while (num) {
                cnt[idx++] += num & 1;
                num = num >> 1;
            }
            right++;

            while (!isValid(cnt) && left < right) {
                num = nums[left];
                idx = 0;
                while (num) {
                    cnt[idx++] -= num & 1;
                    num = num >> 1;
                }
                left++;
            }

            if (isValid(cnt)) {
                res = max(res, right - left);
            }

        }

        return res;
    }
};