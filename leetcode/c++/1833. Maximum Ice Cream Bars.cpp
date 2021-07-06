// 快速排序+贪心
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        int n = costs.size();
        int res = 0;
        sort(costs.begin(), costs.end(), less<int>());
        for (int i = 0; i < n; i++) {
            if (costs[i] <= coins) {
                res++;
                coins -= costs[i];
            }
        }

        return res;
    }
};

// 计数排序+贪心
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        vector<int> count(100001, 0);
        int n = costs.size();
        for (int i = 0; i < n; i++) {
            count[costs[i]]++;
        }

        int res = 0;
        for (int i = 1; i < 100001; i++) {
            if (coins >= i) {
                int curCount = min(count[i], coins / i);
                res += curCount;
                coins -= curCount * i;
            }
        }

        return res;
    }
};