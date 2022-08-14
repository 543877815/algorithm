class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int presum = 0;
        int min_num = 0;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            min_num = min(presum, min_num);
        }


        return min_num > 0 ? min_num : - min_num + 1;
    }
};