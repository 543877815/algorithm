// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int presum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)continue;
            if (nums[i]-presum!= 0) {
                presum = nums[i];
                res++;
            }
        }

        return res;
    }
};