// 最小堆
// 时间复杂度：O(nmlognm)
// 空间复杂度：O(nm)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        long res = 1;
        int m = primes.size();
        priority_queue<long, vector<long>, greater<long>> q;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q.push(res * primes[j]);
            }
            res = q.top();
            q.pop();
            while (!q.empty() && res == q.top()) q.pop();
        }
        return (int) res;
    }
};

// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(n+m)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int m = primes.size();
        vector<int> pointer(m, 1);
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            vector<int> nums(m);
            int minNum = INT_MAX;
            for (int j = 0; j < m; j++) {
                nums[j] = dp[pointer[j]] * primes[j];
                minNum = min(minNum, nums[j]);
            }
            dp[i] = minNum;
            for (int j = 0; j < m; j++) {
                if (minNum == nums[j]) pointer[j]++;
            }
        }
        return dp[n];
    }
};