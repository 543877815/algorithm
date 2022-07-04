// 贪心+优先队列
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector <vector<int>> &stations) {
        if (target == startFuel) return 0;

        priority_queue<int> pq;
        int res = 0;
        int max_dis = startFuel;
        int n = stations.size();
        for (int i = 0; i < n; i++) {
            int dis = stations[i][0], fuel = stations[i][1];
            if (max_dis >= dis) {
                pq.push(fuel);
            } else {
                while (!pq.empty() && max_dis < dis) {
                    max_dis += pq.top();
                    pq.pop();
                    res++;
                }

                if (max_dis < dis) return -1;
                pq.push(fuel);
            }
        }
        while (!pq.empty() && max_dis < target) {
            max_dis += pq.top();
            pq.pop();
            res++;
        }
        if (max_dis < target) return -1;

        return res;
    }
};


// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector <vector<int>> &stations) {
        int n = stations.size();
        vector<long long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }

        return -1;
    }
};