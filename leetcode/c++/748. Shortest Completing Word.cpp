// 时间复杂度：O(nm)
// 空间复杂度：O(26)
class Solution {
public:
    bool checkLetter(char x) {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
    }

    unordered_map<char, int> getMap(string &words) {
        unordered_map<char, int> Map;
        for (char &x : words) {
            if (checkLetter(x)) {
                if (x >= 'A' && x <= 'Z') {
                    x = x - 'A' + 'a';
                }
                Map[x]++;
            }
        }
        return Map;
    }

    bool checkMap(unordered_map<char, int> &licensePlateMap, unordered_map<char, int> &wordMap) {
        for (auto &[key, value] : licensePlateMap) {
            if (licensePlateMap[key] > wordMap[key]) return false;
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        string res;
        unordered_map<char, int> licensePlateMap = getMap(licensePlate);
        int n = words.size();
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> wordMap = getMap(words[i]);

            if (checkMap(licensePlateMap, wordMap) && (res.empty() || res.size() > words[i].size())) {
                res = words[i];
            }
        }

        return res;
    }
};
