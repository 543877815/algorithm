// 思路：把所有数字的二进制表示的每一位都加起来，如果某一位的和能被3整除，那么那个值出现一次的数字二进制表示中对应的那一位就是0，否则是1
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int bitSum[32] = {0};
        for (int i = 0; i < nums.size(); i++) {
            long long bitMask = 1;
            for (int j = 31; j >= 0; j--) {
                int bit = nums[i] & bitMask;
                if (bit != 0) bitSum[j] += 1;
                bitMask = bitMask << 1;
            }
        }
        long long result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result += bitSum[i] % 3;
        }

        return result;
    }
};