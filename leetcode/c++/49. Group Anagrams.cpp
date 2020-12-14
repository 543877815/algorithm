// 排序数组作索引
// 时间复杂度：O(nklogk) n=strs.size()、k=max(str.size())
// 空间复杂度: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> sMat;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++) {
            string stmp = strs[i];
            sort(stmp.begin(), stmp.end());
            sMat[stmp].push_back(i);
        }
        for (auto &key : sMat) {
            vector<string> str(key.second.size());
            for (int value=0; value< key.second.size(); value++) {
                str[value] = strs[key.second[value]];
            }
            result.push_back(str);
            str.clear();
        }
        return result;
    }
};


// 一个更好的写法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <string,vector<string> > m;
        for(string& s : strs)
        {
            string t = s;
            sort(t.begin(),t.end());
            m[t].push_back(s);   //t为单词的按顺序排列，作为key值，m[t]则为该单词的异位词构成的vector，作为value值
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};


// 质数相乘作hash值
// 时间复杂度：O(NK)
// 空间复杂度：O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <double,vector<string> > m;
        double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            double t = 1;
            for(char c : s)
                t *= a[c - 'a'];
            m[t].push_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};


// 计数器作hash值
// 时间复杂度：O(NK)
// 空间复杂度：O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map <string, vector<string>> m;
        for (string &str : strs) {
            // 计数
            int count[26] = {0};
            for (char i : str) {
                count[i - 'a'] += 1;
            }
            // 构建计数hash key
            string key;
            for (int i : count) {
                key += std::to_string(i)  + '#';
            }
            m[key].push_back(str);
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};

// 排序数组作索引
// 时间复杂度：O(nklogk) n=strs.size()、k=max(str.size())
// 空间复杂度: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, int> hash;
        int id = 1;
        for (int i = 0; i < n; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (hash[tmp] == 0) {
                vector<string> t;
                t.push_back(strs[i]);
                res.push_back(t);
                hash[tmp] = id++;
            } else {
                res[hash[tmp]-1].push_back(strs[i]);
            }
        }
        return res;
    }
};