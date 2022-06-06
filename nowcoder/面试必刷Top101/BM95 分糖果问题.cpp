// 贪心
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                left[i] = left[i-1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                right[i] = right[i+1] +1;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(left[i], right[i]);
        }

        return res;
    }
};