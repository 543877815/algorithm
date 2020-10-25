// 动态规划
// 时间复杂度：O(nT)
// 空间复杂度：O(n)
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, INT_MAX-1); // dp[i]表示将区间[0,j)覆盖所需的最少区间的数量
        dp[0] = 0;
        for(int i = 1; i <= T; i++) {
            for (auto& it: clips) {
                cout<< it[0] << " " << it[1] << endl;
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }

        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};


// 贪心算法
// 时间复杂度：O(n+T)
// 空间复杂度：O(n)
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int last=0, ret=0, pre=0;
        for (vector<int> &it: clips) {
            if (it[0] < T) {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++) {
            last = max(last, maxn[i]);
            if (i == last) return -1;
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};