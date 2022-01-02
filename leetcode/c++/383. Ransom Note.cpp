// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        for (auto &x : ransomNote) {
            a[x - 'a']++;
        }

        for (auto &x : magazine) {
            b[x - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) return false;
        }

        return true;
    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        vector<int> a(26, 0);
        for (auto & x : magazine) {
            a[x - 'a']++;
        }

        for (auto & x : ransomNote) {
            a[x - 'a']--;
            if (a[x - 'a'] < 0) return false;
        }
        return true;
    }
};