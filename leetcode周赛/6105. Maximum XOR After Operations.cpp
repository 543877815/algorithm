// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maximumXOR(vector<int> &nums) {
        int n = nums.size();
        vector<int> bin(32, 0);
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            for (int j = 0; j < 32; j++) {
                bin[j] += tmp % 2;
                tmp = tmp / 2;
                if (tmp == 0) break;
            }
        }

        int res = 0;
        long long init = 1;
        for (int i = 0; i < 32; i++) {
            if (bin[i] != 0) res += init;
            init *= 2;
        }

        return res;
    }
};
