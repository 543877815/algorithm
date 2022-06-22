// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int> leftMost = vector<int>(n, 0);
        int most = arr[0];
        for (int i = 1; i < n; i++) {
            leftMost[i] = most;
            if (most < arr[i]) most = arr[i];
        }

        long long res = 0;
        int rightMost = arr.back();
        for (int i = n - 2; i > 0; i--) {
            if (min(leftMost[i], rightMost) > arr[i]) res += min(leftMost[i], rightMost) - arr[i];
            if (rightMost < arr[i]) rightMost = arr[i];
        }
        return res;
    }
};
