// 数学
// 时间复杂度：O(n)
// 空间复杂度：O(1)


class Solution {
public:
    bool xorGame(vector<int> &nums) {
        if (nums.size() % 2 == 0) return true;
        int xornum = 0;
        for (auto num: nums) xornum ^= num;
        return xornum == 0;
    }
};