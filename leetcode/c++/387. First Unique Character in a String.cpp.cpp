// 哈希表
// 时间复杂度: O(n)
// 空间复杂度：O(26)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            hash[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (hash[s[i]] == 1) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (hash[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};