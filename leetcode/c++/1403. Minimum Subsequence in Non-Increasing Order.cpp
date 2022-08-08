// ����
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<>());
        int total = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            res.push_back(nums[i]);
            if (total > sum - total) break;;
        }

        return res;
    }
};