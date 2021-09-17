// 双指针
// 时间复杂度：O(d×(m+n))
// 空间复杂度：O(1)
class Solution {
public:
    string findLongestWord(string s, vector <string> &dictionary) {
        int n = s.size();
        int m = dictionary.size();
        string res = "";
        for (int i = 0; i < m; i++) {
            int si = 0;
            int di = 0;
            while (di < dictionary[i].size() && si < n) {
                while (si < n && di < dictionary[i].size() && s[si] == dictionary[i][di]) {
                    si++;
                    di++;
                }
                while (si < n && s[si] != dictionary[i][di]) {
                    si++;
                }
            }

            if (di == dictionary[i].size()) {
                if (res == "") res = dictionary[i];
                else if (res.size() < dictionary[i].size()) res = dictionary[i];
                else if (res.size() == dictionary[i].size() && res > dictionary[i]) res = dictionary[i];
            }
        }

        return res;
    }
};

// 时间复杂度：O(d×m×logd+d×(m+n))
// 空间复杂度：O(dxm)
// 排序+贪心+双指针
class Solution {
public:
    string findLongestWord(string s, vector <string> &dictionary) {
        int n = s.size();
        int m = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), [&](string &x, string &y) {
            if (x.size() != y.size()) return x.size() > y.size();
            else return x < y;
        });
        for (int i = 0; i < m; i++) {
            int si = 0;
            int di = 0;
            while (di < dictionary[i].size() && si < n) {
                while (si < n && di < dictionary[i].size() && s[si] == dictionary[i][di]) {
                    si++;
                    di++;
                }
                while (si < n && s[si] != dictionary[i][di]) {
                    si++;
                }
            }

            if (di == dictionary[i].size()) return dictionary[i];
        }

        return "";
    }
};