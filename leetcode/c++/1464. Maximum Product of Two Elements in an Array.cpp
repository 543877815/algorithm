// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(logn)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
};