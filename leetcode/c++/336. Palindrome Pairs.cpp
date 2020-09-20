// 哈希表+翻转
// 时间复杂度：O(n*m^2)
// 空间复杂度：O(n*m)
class Solution {
private:
    vector <string> reverseWord;
    unordered_map<string, int> wordId;

    bool isPalindrome(string s) {
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

public:
    vector <vector<int>> palindromePairs(vector <string> &words) {
        vector <vector<int>> res;
        if (words.size() <= 1) return res;
        for (string word: words) {
            reverseWord.push_back(word);
            reverse(reverseWord.back().begin(), reverseWord.back().end());
        }

        for (int i = 0; i < reverseWord.size(); i++) {
            wordId[reverseWord[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string currWord = words[i];
            auto iter = wordId.find("");
            if (isPalindrome(currWord) && iter != wordId.end() && currWord != "") {
                res.push_back({iter->second, i});
            }
            for (int j = 0; j < currWord.size(); j++) {
                string left = currWord.substr(0, j);
                string right = currWord.substr(j);

                // 左边是回文，右边是翻转且不是自己
                iter = wordId.find(right);
                if (isPalindrome(left) && iter != wordId.end() && iter->second != i) {
                    res.push_back({iter->second, i});
                }
                // 右边是回文，左边是翻转且不是自己
                iter = wordId.find(left);
                if (isPalindrome(right) && iter != wordId.end() && iter->second != i) {
                    res.push_back({i, iter->second});
                }
            }
        }

        return res;
    }
};


// 优化
// 使用引用
// 将string替换成string_view
class Solution {
private:
    vector <string> reverseWord;
    unordered_map<string_view, int> wordId;

    bool isPalindrome(string_view &s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[left + i] != s[right - i]) {
                return false;
            }
        }
        return true;
    }

    int findWord(string_view &word, int left, int right) {
        auto iter = wordId.find(word.substr(left, right - left + 1));
        return iter == wordId.end() ? -1 : iter->second;
    }

public:
    vector <vector<int>> palindromePairs(vector <string> &words) {
        vector <vector<int>> res;
        if (words.size() <= 1) return res;
        for (string word: words) {
            reverseWord.push_back(word);
            reverse(reverseWord.back().begin(), reverseWord.back().end());
        }

        for (int i = 0; i < reverseWord.size(); i++) {
            wordId[reverseWord[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string_view currWord(words[i]);
            int m = currWord.size();
            auto iter = wordId.find("");
            if (isPalindrome(currWord, 0, m - 1) && iter != wordId.end() && currWord != "") {
                res.push_back({iter->second, i});
            }
            for (int j = 0; j < m; j++) {

                // 左边是回文，右边是翻转且不是自己
                int right_id = findWord(currWord, 0, j - 1);
                if (isPalindrome(currWord, j, m - 1) && right_id != -1 && right_id != i) {
                    res.push_back({i, right_id});
                }

                // 右边是回文，左边是翻转且不是自己
                int left_id = findWord(currWord, j, m - 1);
                if (isPalindrome(currWord, 0, j - 1) && left_id != -1 && left_id != i) {
                    res.push_back({left_id, i});
                }
            }
        }

        return res;
    }
};