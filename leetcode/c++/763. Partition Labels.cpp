// 贪心+双指针
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> res;
        unordered_map<char, int> hash_map; // 记录字母i最后出现的位置
        for (int i = 0; i < S.size(); i++) {
            hash_map[S[i]] = i;
        }
        int left = 0, right = 0;
        while(left < n) {
            right = max(right, hash_map[S[left]]);
            if (left == right) {
                res.push_back(left);
            }
            left++;
        }
        for (int i = res.size() - 1; i > 0; i--) {
            res[i] = res[i] - res[i-1];
        }
        res[0] += 1;

        return res;
    }
};