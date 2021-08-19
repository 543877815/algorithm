// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int b1 = 0; // 出现一次的位
        int b2 = 0; // 出现两次的位
        for (auto &num : nums) {
            b1 = (b1 ^ num) & ~b2; // 既不在出现一次的b1，也不在出现两次的b2里面，我们就记录下来，出现了一次，再次出现则会抵消
            b2 = (b2 ^ num) & ~b1; // 既不在出现两次的b2里面，也不再出现一次的b1里面(不止一次了)，记录出现两次，第三次则会抵消
        }

        return b1;
    }
};

// 依次确定每一个二进制位
// 时间复杂度：O(nlogC)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

