// 滑动窗口 + 有序集合
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size();
        multiset<int> s;
        int left = 0, right = 0;
        int res = 0;
        while (right < n) {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};

// 滑动窗口 + 单调队列
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size();
        deque<int> queMax, queMin;
        int left = 0, right = 0;
        int res = 0;
        while (right < n) {
            while (!queMax.empty() && queMax.back() < nums[right]) queMax.pop_back();
            while (!queMin.empty() && queMin.back() > nums[right]) queMin.pop_back();
            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit) {
                if (nums[left] == queMin.front()) queMin.pop_front();
                if (nums[left] == queMax.front()) queMax.pop_front();
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};