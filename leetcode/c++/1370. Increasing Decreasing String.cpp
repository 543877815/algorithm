// map
// 空间复杂度：O(n)
// 时间复杂度：O(n^2)
class Solution {
public:
    string sortString(string s) {
        map<char, int> record;
        int m = s.size();
        for (int i = 0; i < m; i++) {
            record[s[i]]++;
        }
        string res;
        int count = m;
        while (count != 0) {
            for (map<char, int>::iterator it = record.begin(); it != record.end(); it++) {
                if (it->second != 0) {
                    it->second--;
                    res.push_back(it->first);
                    count--;
                }
            }
            if (count != 0) {
                for (map<char, int>::reverse_iterator it = record.rbegin(); it != record.rend(); it++) {
                    if (it->second != 0) {
                        it->second--;
                        res.push_back(it->first);
                        count--;
                    }
                }
            }
        }
        return res;
    }
};


// vector
// 空间复杂度：O(26)
// 时间复杂度：O(26n)
class Solution {
public:
    string sortString(string s) {
        vector<int> record(26, 0);
        int m = s.size();
        for (int i = 0; i < m; i++) {
            record[s[i] - 'a']++;
        }
        string res;
        while (m != 0) {
            for (int i = 0; i < 26; i++) {
                if (record[i] != 0) {
                    record[i]--;
                    res.push_back(i + 'a');
                    m--;
                }
            }
            if (m != 0) {
                for (int i = 25; i >= 0; i--) {
                    if (record[i] != 0) {
                        record[i]--;
                        res.push_back(i + 'a');
                        m--;
                    }
                }
            }
        }
        return res;
    }
};