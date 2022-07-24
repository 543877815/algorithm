class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        if (nums.back() > target) return false;

        int size = 1 << n;
        vector<bool> dp(size, false);
        dp[0] = true;

        vector<int> currentSum = vector<int>(size);
        for (int i = 0; i < size; i++) {
            // ���ǻ��� dp[i] = true ��ǰ���½���״̬ת��
            if (!dp[i]) continue;

            // ���ڵ�ǰ״̬�����һ�����Ժ�
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) continue;
                int next = i | (1 << j);
                if (dp[next]) continue;
                if ((currentSum[i] % target) + nums[j] <= target) {
                    currentSum[next] = currentSum[i] + nums[j];
                    dp[next] = true;
                } else {
                    // ���������Ѿ��ź������ (currentSum[i] % target) + nums[j] > target��ʣ�µ�����û�б�Ҫö��
                    break;
                }
            }
        }
        return dp[size - 1];
    }
};