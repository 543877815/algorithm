// 构造
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res = vector<int>(n);
        for (int i = 0; i < n - k - 1; i++) {
            res[i] = i + 1;
        }
        int index = 0;
        int left = n - k;
        int right = n;
        for (int i = n - k - 1; i < n; i++) {
            if (index % 2 == 0) {
                res[i] = left;
                left++;
            } else {
                res[i] = right;
                right--;
            }
            index++;
        }
        return res;
    }
};
