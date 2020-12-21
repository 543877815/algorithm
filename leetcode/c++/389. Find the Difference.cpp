
// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
char findTheDifference(char * s, char * t){
    int length1 = strlen(s);
    int length2 = strlen(t);
    int sum = 0;
    for (int i = 0; i < length1; i++) {
        sum ^= s[i] - 'a';
    }
    for (int i = 0; i < length2; i++) {
        sum ^= t[i] - 'a';
    }
    return 'a' + sum;
}



// 时间复杂度：O(n+m+26)
// 空间复杂度：O(26)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for (auto &x : s) hash[x]++;
        for (auto &x : t) hash[x]--;
        for (auto &x : hash) {
            if (x.second != 0) return x.first;
        }
        return 'a';
    }
};