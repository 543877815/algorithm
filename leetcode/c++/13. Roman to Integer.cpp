int indexOf(char* str, char ch){
    int index = 0;
    char tmp=str[index];
    while( tmp != '\0'){
        if(tmp == ch){
            return index;
        }
        index++;
        tmp = str[index];
    }
    return -1;
}


int romanToInt(char * s){
    char romanChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int nums[7] = {1, 5, 10, 50, 100, 500, 1000};
    int length = strlen(s);
    int ans = 0;
    for (int i = 0; i < length - 1; i++) {
        if (indexOf(romanChar, s[i]) < indexOf(romanChar, s[i + 1])) {
            ans -= nums[indexOf(romanChar, s[i])];
        } else {
            ans += nums[indexOf(romanChar, s[i])];
        }
    }
    
    ans += nums[indexOf(romanChar, s[length - 1])];
    return ans;
}


class Solution {
public:
    unordered_map<char, int> symbol2value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int value = symbol2value[s[i]];
            if (i < n - 1 && value < symbol2value[s[i+1]]) {
                res -= value;
            } else {
                res += value;
            }
        }

        return res;
    }
};