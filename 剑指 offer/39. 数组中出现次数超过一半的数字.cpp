class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int vote = 0, mode = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (vote == 0) mode = nums[i];
            if (nums[i] == mode) vote++;
            else vote--;
        }
        return mode;
    }
};