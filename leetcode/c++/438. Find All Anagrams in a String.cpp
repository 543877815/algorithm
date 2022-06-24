// 242.Valid Anagram

// out of time
// 时间复杂度: O(nm)
// 空间复杂度: O(m)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = p.size()-1;
        vector<int> result;
        while(right < s.size()) {
            string subString = s.substr(left, p.size());
            if (isAnagram(subString, p)) result.push_back(left);
            left++;
            right++;
        }
        return result;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> sMat;
        for(int i = 0; i < s.size(); i++) {
            sMat[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            sMat[t[i]]--;
        }
        for(int i = 0; i < t.size(); i++) {
            if(sMat[t[i]] != 0) return false;
        }
        return true;
    }
};

// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq_s(26, 0), freq_p(26, 0), res;
        for (auto &c : p) {
            freq_p[c-'a']++;
        }
        int left = 0, right = 0;
        while(right < s.size()) {
            freq_s[s[right]-'a']++;
            if (right < p.size()-1) {
                right++;
                continue;
            }
            if (freq_s == freq_p) res.push_back(left);
            freq_s[s[left]-'a']--;
            right++;
            left++;
        }
        return res;
    }
};

// 2022.06.23
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> res;
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return res;
        vector<int> s_m (26, 0);
        vector<int> p_m (26, 0);
        for (int i = 0; i < m; i++) {
            p_m[p[i] - 'a']++;
        }

        int left = 0, right = 0;
        while (right < m) {
            s_m[s[right] - 'a']++;
            right++;
        }
        while (right < n) {
            if (s_m == p_m) res.push_back(left);
            s_m[s[left] - 'a']--;
            s_m[s[right] - 'a']++;
            left++;
            right++;
        }

        if (s_m == p_m) res.push_back(left);

        return res;
    }
};
