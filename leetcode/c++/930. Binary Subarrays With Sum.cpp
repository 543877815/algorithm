// 前缀和+哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size();
        if (n == 0) return 0;
        int presum = 0;
        int res = 0;
        unordered_map<int, int> record;
        record[0] = 1;
        for (int x : nums) {
            presum += x;
            if (record.find(presum - goal) != record.end()) {
                res += record[presum - goal];
            }
            record[presum]++;
        }

        return res;
    }
};

// 三指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size();
        if (n == 0) return 0;
        int iLo = 0, iHi = 0;
        int sumLo = 0, sumHi = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sumLo += nums[i];
            while (iLo < i && sumLo > goal) {
                sumLo -= nums[iLo++];
            }

            sumHi += nums[i];
            while (iHi < i && (sumHi > goal || sumHi == goal && nums[iHi] == 0)) {
                sumHi -= nums[iHi++];
            }
            if (sumLo == goal) {
                res += iHi - iLo + 1;
            }
        }

        return res;
    }
};