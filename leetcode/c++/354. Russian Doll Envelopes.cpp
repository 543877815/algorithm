// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int maxEnvelopes(vector <vector<int>> &envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            if (int num = envelopes[i][1]; num > f.back()) {
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num); // 第一个出现的位置
                *it = num;
            }
        }
        return f.size();
    }
};


// 空间复杂度：O(n)
// 时间复杂度：O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>&x, vector<int>&y) {
            if (x[0] != y[0]) return x[0] < y[0];
            else return x[1] < y[1];
        });
        int n = envelopes.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }

        return res;
    }
};