// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int res = INT_MIN, count = 0, first = INT_MIN, second = INT_MIN, third = INT_MIN, N_first = INT_MAX, N_second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                first = nums[i];
                count++;
            } else if (count == 1) {
                second = nums[i];
                count++;
            } else if (count == 2) {
                third = nums[i];
                count++;
            } else if (count == 3 && third < nums[i]) {
                third = nums[i];
            }

            if (nums[i] < N_second) N_second = nums[i];

            if (N_second < N_first) swap(N_second, N_first);
            if (third > second) swap(third, second);
            if (second > first) swap(second, first);

        }
        return max(N_first * N_second * first, first * second * third);
    }
};