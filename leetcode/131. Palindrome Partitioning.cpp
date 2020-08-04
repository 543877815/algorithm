// 回溯
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    vector <vector<string>> res;
public:
    bool isPalindrome(const string &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }

    void DFS(const string &s, int begin, vector <string> &tmp) {
        if (s.size() == begin) {
            res.push_back(tmp);
            return;
        }
        for (int i = 1; i + begin <= s.size(); i++) {
            string substring = s.substr(begin, i);
            if (!substring.empty() && isPalindrome(substring)) {
                tmp.push_back(substring);
                DFS(s, i + begin, tmp);
                tmp.pop_back();
            }
        }

    }

    vector <vector<string>> partition(string s) {
        if (s.empty()) return res;
        vector <string> tmp;
        DFS(s, 0, tmp);
        return res;
    }
};