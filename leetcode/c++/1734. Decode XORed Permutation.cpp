// 位运算
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size();
        int x = 1;
        for (int i = 2; i <= n + 1; i++) {
            x ^= i;  // perm[0] ^ perm[1] ^ ... ^ perm[n+1]
        }
        for (int i = 1; i < n; i += 2) {
            x ^= encoded[i];
        }
        vector<int> perm = {x};
        for (int i = 1; i <= n; i++) {
            perm.push_back(perm.back() ^ encoded[i - 1]);
        }
        return perm;
    }
};