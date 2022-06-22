// 动态规划+二分查找
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int> &a) {
        // write code here
        int n = a.size();
        if (n == 0) return 0;
        // dp[i]表示长度为 i 的最长上升子序列的末尾元素的最小值
        vector<int> dp(n + 1, 0);
        int len = 1;
        dp[len] = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > dp[len]) {
                dp[++len] = a[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (dp[mid] < a[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[pos + 1] = a[i];
            }
        }
        return len;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& a) {
        // write code here
        int n = a.size();
        if (n == 0) return 0;
        // dp[i]表示长度为 i 的最长上升子序列的末尾元素的最小值
        vector<int>dp(n+1, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = res;
            while (left < right) {
                int mid = (left + right) / 2;
                if (dp[mid] < a[i]) left = mid + 1;
                else right = mid;
            }
            dp[left] = a[i];
            if (res == right) res++;
        }
        return res;
    }
};