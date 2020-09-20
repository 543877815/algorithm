int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    int maxLength = 0;
    if(length == 0)return maxLength;
    int CurrentLength = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < length; i++) {
        int flag = 0;
        for (int j = start; j < end; j++) {
            if (s[i] == s[j] && start != end){
                start = j + 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            CurrentLength ++;
        }  else { 
            CurrentLength = end - start + 1;
        }
        
        end++;
        
        if (CurrentLength > maxLength){
            maxLength = CurrentLength;
        }
        
    }
    return maxLength;
}



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = 0;
        int res = 0;
        while(l < s.size()) {
            if(freq[s[r]] == 0) {
                freq[s[r++]]++;
            } else {
                freq[s[l++]]--;
            }
            res = max(res, r-l);
        }

        return res;
    }
};

// 双索引法
// 空间复杂度: O(1)
// 时间复杂度：O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;
        while(l < s.size()) {
            if(r+1<s.size() && freq[s[r+1]] == 0) {
                freq[s[++r]]++;
            } else {
                freq[s[l++]]--;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = 0;
        int res = 0;
        while(l < s.size()) {
            if(r<s.size() && freq[s[r]] == 0) {
                freq[s[r++]]++;
            } else {
                freq[s[l++]]--;
            }
            res = max(res, r-l);
        }

        return res;
    }
};


