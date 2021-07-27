// 1143.最长公共子序列(超时)
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = arr.size();
        int n = target.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i-1] == target[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return n - dp[m][n];
    }
};

// 300.最长上升子序列
// 时间复杂度：O(nlogn+m)
// 空间复杂度：O(n+n)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            hashmap[target[i]] = i+1;
            target[i] = i;
        }
        vector<int> newArr;
        for (int i = 0; i < m; i++) {
            if (hashmap[arr[i]] != 0) newArr.push_back(hashmap[arr[i]] - 1);
        }
        return n - lengthofLIS(newArr);
    }

    int lengthofLIS(vector<int>& nums) {
        int len = 1, n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n+1, 0);
        // 维护一个数组 dp[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值
        dp[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len]) dp[++len] = nums[i];
            else {
                // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                int left = 1, right = len, pos = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (dp[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                dp[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

// 二分查找巧妙利用 lower_bound 函数
// https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/
class Solution {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        vector<int> d;
        for (int val : arr) {
            if (pos.count(val)) {
                int idx = pos[val];
                auto it = lower_bound(d.begin(), d.end(), idx);
                if (it != d.end()) {
                    *it = idx;
                } else {
                    d.push_back(idx);
                }
            }
        }
        return n - d.size();
    }
};

