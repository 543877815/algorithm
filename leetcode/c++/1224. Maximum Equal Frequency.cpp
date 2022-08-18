// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < n; i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||   // 最大出现次数
                      freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||  // 所有数的出现次数都是 maxFreq 或 maxFreq?1，并且最大出现次数的数只有一个
                      freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;  // 除开一个数，其他所有数的出现次数都是 maxFreqmaxFreq，并且该数的出现次数为 11
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};