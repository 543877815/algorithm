// 时间复杂度：O(nlogC)
// 空间复杂度：O(nlogC)
static constexpr int DIGIT = 30;
class Trie {
public:
    Trie* zero;
    Trie* one;
    Trie() {
        zero = nullptr;
        one = nullptr;
    };

    void insert(int num) {
        Trie* curr = this;
        for (int i = DIGIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (!curr->zero) curr->zero = new Trie();
                curr = curr->zero;
            } else {
                if (!curr->one) curr->one = new Trie();
                curr = curr->one;
            }
        }
    }

    int check(int num) {
        Trie* curr = this;
        int res = 0;
        for (int i = DIGIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 1) {
                if (curr->zero) {
                    curr = curr->zero;
                    res = res * 2 + 1;
                } else {
                    curr = curr->one;
                    res = res * 2;
                }
            } else {
                if (curr->one) {
                    curr = curr->one;
                    res = res * 2 + 1;
                } else {
                    curr = curr->zero;
                    res = res * 2;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie *root = new Trie();
        int res = 0;
        for (int i = 1; i < n; i++) {
            root->insert(nums[i-1]);
            res = max(res, root->check(nums[i]));
        }
        return res;
    }
};