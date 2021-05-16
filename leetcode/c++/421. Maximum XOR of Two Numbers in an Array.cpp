// 直接遍历
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};

// 哈希表
// 时间复杂度：O(nlogC)，枚举一个二进制位的时间复杂度为O(logC)
// 空间复杂度：O(n)
class Solution {
private:
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; k--) {
            unordered_set<int> seen;
            // 将所有的 pre^k(a_j) 放入哈希表中
            for (int num: nums) {
                // 如果只想保留从最高位开始到第 k 个二进制为止的部分
                // 只需将其右移 k 位
                seen.insert(num >> k);
            }

            // 目前 x 包含从最高位开始到第 k + 1 二进制位位置的部分
            // 我们将 x 的第 k 个二进制位位置 1, 即为 x = x * 2 + 1
            int x_next = x * 2 + 1;
            bool found = false;

            // 枚举 i
            for (int num: nums) {
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) x = x_next;
            else x = x_next - 1;
        }

        return x;
    }
};