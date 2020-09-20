class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int res = INT_MIN, count = 0, first = INT_MIN, second = INT_MIN, third = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                first = nums[i];
                count++;
            } else if (count == 1 && first != nums[i]) {
                second = nums[i];
                count++;
            } else if (count == 2 && second != nums[i] && first != nums[i]) {
                third = nums[i];
                count++;
            } else if (count == 3 && third < nums[i] && second != nums[i] && first != nums[i]) {
                third = nums[i];
            }

            if (third > second) swap(third, second);
            if (second > first) swap(second, first);

            res = max(res, nums[i]);
        }

        return count == 3 ? third : res;
    }
};