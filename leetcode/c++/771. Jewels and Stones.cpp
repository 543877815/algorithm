// 时间复杂度：O(nlogn+mlogm+n+m)
// 空间复杂度：O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());
        int i = 0, j = 0, res = 0;
        while (i < J.size() && j < S.size()) {
            while (i < J.size() && j < S.size() && J[i] == S[j]) {
                j++;
                res++;
            }
            if (J[i] < S[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

// 空间复杂度：O(n)
// 时间复杂度：O(n+m)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> hash;
        for (int i = 0; i < J.size(); i++) {
            hash[J[i]] = true;
        }

        int res = 0;
        for (int i = 0; i < S.size(); i++) {
            if (hash[S[i]] == true) res++;
        }

        return res;
    }
};