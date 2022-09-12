// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(logn)
class Solution {
public:
    int specialArray(vector<int> &nums) {
        int n = nums.size();
        int res = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.back(); i++) {
            int idx = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (n - idx == i) return i;
        }

        return -1;
    }
};