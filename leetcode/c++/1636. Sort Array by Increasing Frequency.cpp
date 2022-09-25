// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    vector<int> frequencySort(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int x: nums) {
            freq[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int x, int y) {
            if (freq[x] != freq[y]) return freq[x] < freq[y];
            else return x > y;
        });

        return nums;
    }
};