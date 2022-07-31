// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
    const int MAXP = 30;

public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        set<int> st;
        for (int x: nums) st.insert(x);
        vector<int> cnt(MAXP + 1);
        for (int x: st) {
            int t = __builtin_popcount(x);
            cnt[t]++;
        }

        long long ans = 0;
        for (int i = 0; i <= MAXP; i++) {
            for (int j = 0; j <= MAXP; j++) {
                if (i + j >= k) {
                    ans += 1LL * cnt[i] * cnt[j];
                }
            }
        }
        return ans;
    }
};