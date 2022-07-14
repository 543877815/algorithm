// 哈希表
// 时间复杂度：O(n^3)
// 空间复杂度：O(n)
class Solution {
public:
    int lenLongestFibSubseq(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        unordered_map<int, int> mymap;
        for (int i = 0; i < n; i++) {
            mymap[arr[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j];
                int sum = a + b;
                int tmp = 0;
                while (mymap.count(sum)) {
                    a = b;
                    b = sum;
                    sum = a + b;
                    tmp = tmp == 0 ? 3 : tmp + 1;
                }
                res = max(res, tmp);
            }
        }

        return res;
    }
};

// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> indices;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            indices[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--) {
                int k = -1;
                if (indices.count(arr[i] - arr[j])) {
                    k = indices[arr[i] - arr[j]];
                }
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
