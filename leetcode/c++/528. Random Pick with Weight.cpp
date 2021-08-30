// 前缀和+二分搜索
// 时间复杂度：O(n) + O(logn)
// 空间复杂度：O(n)
#define RAND_MAX Ox7FFF

class Solution {
public:
    vector<int> presum;

    Solution(vector<int> &w) {
        int n = w.size();
        presum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + w[i];
        }
    }

    int pickIndex() {
        int n = presum.size();
        int remain = presum[n - 1];
        int rand_num = rand() % remain;
        auto pos = upper_bound(presum.begin(), presum.end(), rand_num);
        return pos - presum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */