// 动态规划+二分查找
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        int n = arr.size();
        // dp[i]表示长度为 i 的最长上升子序列的末尾元素的最小值.
        // p[i]表示当前元素对应的长度
        vector<int> dp(n + 1, -1), p(n);
        int len = 1;//初始化长度为1，元素为序列第一个数字
        dp[len] = arr[0];
        p[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(arr[i] > dp[len]) {
                //此时将该数字添加到末尾
                dp[++len] = arr[i];
                p[i] = len;
            } else {
                //二分查找恰好合适的位置
                int left = 1, right = len, pos = 0;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    if(dp[mid] < arr[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                //对该位置数字进行更新
                dp[pos + 1] = arr[i];
                p[i] = pos + 1;
            }
        }
        vector<int> ans(len);
        //逆向查找对应序列值
        for(int i = n - 1; i >= 0; --i) {
            if(p[i] == len) {
                ans[--len] = arr[i];
            }
        }
        return ans;
    }
};