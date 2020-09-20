// 使用 map
// 空间复杂度：O(n)
// 时间复杂度: O(n)
typedef pair<char,int> PAIR;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto &c : s) {
            freq[c]++;
        }
        vector<PAIR> freq_sort;
        for (auto &m : freq) {
            freq_sort.push_back(m);
        }
        sort(freq_sort.begin(), freq_sort.end(), [](const PAIR& l, const PAIR& r) {
            return l.second > r.second;
        });
        string res;
        for (auto iter=freq_sort.begin(); iter != freq_sort.end(); iter++) {
            res += string(iter->second, iter->first);
        }
        return res;
    }
};
