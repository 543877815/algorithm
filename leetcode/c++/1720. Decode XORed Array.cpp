// 异或运算
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        int n = encoded.size();
        vector<int> res = {first};
        for (int i = 0; i < n; i++) {
            res.push_back(res[i] ^ encoded[i]);
        }

        return res;
    }
};