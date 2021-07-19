// 质数相乘作hash值
// 时间复杂度：O(NK)
// 空间复杂度：O(NK)
class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        vector <vector<string>> res;
        unordered_map<double, vector<string> > m;
        double a[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                        101};
        for (string &s : strs) {
            double t = 1;
            for (char c : s)
                t *= a[c - 'a'];
            m[t].push_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for (auto &n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};