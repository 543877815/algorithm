// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char, bool> isVowels;
        isVowels['a'] = true;
        isVowels['e'] = true;
        isVowels['i'] = true;
        isVowels['o'] = true;
        isVowels['u'] = true;
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            if (isVowels[s[i]])
                sum++;
        }
        int left = 0, right = k;
        int res = sum;
        while (right < n && left < n) {
            if (isVowels[s[right]]) {
                sum++;
            }
            if (isVowels[s[left]]) {
                sum--;
            }
            right++;
            left++;
            res = max(res, sum);
        }
        return res;
    }
};