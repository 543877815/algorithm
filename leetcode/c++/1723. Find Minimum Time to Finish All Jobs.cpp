// 回溯
// 时间复杂度：O(nlogn+log(S-M)xk^n)
// 空间复杂度：O(n)
class Solution {
public:
    bool backtrack(vector<int> &jobs, vector<int> &workloads, int idx, int limit) {
        if (idx >= jobs.size()) return true;
        int cur = jobs[idx];
        for (auto &workload: workloads) {
            if (workload + cur <= limit) {
                workload += cur;
                if (backtrack(jobs, workloads, idx + 1, limit)) return true;
                workload -= cur;
            }
            if (workload == 0 || workload + cur == limit) break;
        }

        return false;
    }

    bool check(vector<int> &jobs, int k, int limit) {
        vector<int> workloads(k, 0);
        return backtrack(jobs, workloads, 0, limit);
    }

    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), greater<int>());
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(jobs, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// 动态规划+状态压缩
// 时间复杂度：O(nx3^n)
// 空间复杂度：O(nx2^n)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);  // x表示选i，y表示不选i
            sum[i] = sum[y] + jobs[x];  // 类似前缀和
        }

        vector<vector<int>> dp(k, vector<int>(1 << n)); // dp[i][j] 表示给前i个人分配工作，工作的分配情况为j时，完成所有工作的最短时间。
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }

        for (int i = 1; i < k; i++) {   // 遍历员工
            for (int j = 0; j < (1 << n); j++) {   // 遍历分配的工作
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {   // 遍历最小工作的可能性
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }

        return dp[k-1][(1 << n) - 1];
    }
};