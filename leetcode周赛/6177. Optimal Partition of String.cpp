// 贪心
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isValid(vector<int> &counter) {
        for (int i = 0; i < counter.size(); i++) {
            if (counter[i] > 1) return false;
        }
        return true;
    }

    void init(vector<int> &counter) {
        for (int i = 0; i < counter.size(); i++) {
            counter[i] = 0;
        }
    }

    int partitionString(string s) {
        int n = s.size();
        int res = 0, right = 0;
        vector<int> counter(26, 0);
        for (int i = 0; i < n; i++) {
            counter[s[i] - 'a']++;
            if (!isValid(counter)) {
                init(counter);
                counter[s[i] - 'a']++;
                res++;
            }
        }
        return res + 1;
    }
};