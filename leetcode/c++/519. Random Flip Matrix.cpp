// 拒绝采样
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int m, n;
    unordered_set<int> record;

    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }

    vector<int> flip() {
        while (true) {
            int index = rand() % (m * n);
            if (!record.count(index)) {
                record.insert(index);
                return {index / n, index % n};
            }
        }

    }

    void reset() {
        record.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */