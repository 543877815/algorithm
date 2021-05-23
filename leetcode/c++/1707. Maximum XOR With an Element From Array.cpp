// 暴力解法
// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector <vector<int>> &queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int xi = queries[i][0], mi = queries[i][1];
                if (nums[j] > mi) continue;
                else res[i] = max(res[i], nums[j] ^ xi);
            }
        }

        return res;
    }
};


class Trie {
public:
    const int L = 30;
    Trie *children[2] = {};

    // 构造字典树
    void insert(int val) {
        Trie *node = this;
        for (int i = L - 1; i >= 0; i--) {
            int bit = (val >> i) & 1; // 提取位数
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val) {
        int res = 0;
        Trie *node = this;
        for (int i = L - 1; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr) {
                res |= 1 << i;  // 有1取1
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return res;
    }
};


// 前缀树 + 离线匹配
// 时间复杂度：O(NlogN+QlogQ+(N+Q)*L)
// 空间复杂度：O(Q+NL)
class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector <vector<int>> &queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);  // 序号
        }
        // 根据 mi 进行排序
        sort(queries.begin(), queries.end(), [&](auto &x, auto &y) {
            return x[1] < y[1];
        });

        vector<int> res(m);

        Trie *t = new Trie();
        int idx = 0;
        for (auto &q: queries) {
            int x = q[0], k = q[1], qid = q[2];
            while (idx < n && nums[idx] <= k) {
                t->insert(nums[idx]);
                idx++;
            }
            if (idx == 0) res[qid] = -1; // 字典树为空
            else res[qid] = t->getMaxXor(x);
        }

        return res;
    }
};

// 前缀树 + 在线匹配
// 时间复杂度：O((N+Q)*L)
// 空间复杂度：O(N*L)
class Trie {
public:
    const int L = 30;

    Trie *children[2] = {};
    int min = INT_MAX;

    void insert(int val) {
        Trie *node = this;
        node->min = std::min(node->min, val);
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->min = std::min(node->min, val);
        }
    }

    int getMaxXorWithLimit(int val, int limit) {
        Trie *node = this;
        if (node->min > limit) {
            return -1;
        }
        int ans = 0;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr && node->children[bit ^ 1]->min <= limit) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector <vector<int>> &queries) {
        Trie *t = new Trie();
        for (int val : nums) {
            t->insert(val);
        }
        int numQ = queries.size();
        vector<int> ans(numQ);
        for (int i = 0; i < numQ; ++i) {
            ans[i] = t->getMaxXorWithLimit(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};
