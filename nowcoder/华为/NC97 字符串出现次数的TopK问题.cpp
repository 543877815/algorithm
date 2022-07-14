// ÅÅÐò
// Ê±¼ä¸´ÔÓ¶È£ºO(nlogn)
// ¿Õ¼ä¸´ÔÓ¶È£ºO(n)
class Solution {
public:
    /**
     * return topK string
     * @param strings string×Ö·û´®vector strings
     * @param k intÕûÐÍ the k
     * @return string×Ö·û´®vector<vector<>>
     */
    vector <vector<string>> topKstrings(vector <string> &strings, int k) {
        // write code here
        int n = strings.size();
        unordered_map<string, int> mymap;
        for (int i = 0; i < n; i++) {
            mymap[strings[i]]++;
        }

        vector <pair<string, int>> str_freq;
        for (auto &[key, value]: mymap) {
            str_freq.push_back(make_pair(key, value));
        }

        sort(str_freq.begin(), str_freq.end(), [&](const pair<string, int> &a, const pair<string, int> &b) -> int {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
        });

        vector <vector<string>> res;
        for (int i = 0; i < k; i++) {
            vector <string> tmp = {str_freq[i].first, to_string(str_freq[i].second)};
            res.push_back(tmp);
        }
        return res;
    }
};