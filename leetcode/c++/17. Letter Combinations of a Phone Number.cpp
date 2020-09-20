
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void getLetterCom(char **res, char *digits, char *tmp, int index, int *size, char map[10][5]) {
    int digit = digits[index] - '0';
    if (digits[index] == 0) {
        char *letters = (char *) malloc(sizeof(char) * (index + 1));
        tmp[index] = 0;
        strcpy(letters, tmp);
        res[(*size)++] = letters;
        return;
    }
    for (int i = 0; map[digit][i]; i++) {
        tmp[index] = map[digit][i];
        getLetterCom(res, digits, tmp, index + 1, size, map);
    }
    return;
}


char **letterCombinations(char *digits, int *returnSize) {
    char map[10][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size = 0;

    // compute malloc memory
    int loc = 0;
    int num = 1;
    while (digits[loc]) {
        if (digits[loc] == '0' || digits[loc] == '1') continue;
        else if (digits[loc] == '7' || digits[loc] == '9') num *= 4;
        else num *= 3;
        loc++;
    }
    char **res = (char **) malloc(sizeof(char *) * num);
    int length = strlen(digits);
    for (int i = 0; i < num; i++) {
        res[i] = (char *) malloc(sizeof(char) * length);
    }

    if (loc == 0) {
        *returnSize = 0;
        return res;
    }

    char *tmp = (char *) malloc(sizeof(char) * num);
    getLetterCom(res, digits, tmp, 0, &size, map);
    *returnSize = size;
    return res;
}


// c++
// 时间复杂度：O(3^n+4^m)
// 空间复杂度：O(3^n+4^m)
class Solution {
private:
    const string letterMap[10]{
            " ",    // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
    };
    vector <string> res;

    // s中保存了此时从digits[0...index-1] 翻译的得到的一个字母字符串
    // 寻找和digits[index]匹配的字母，获得digit[0...index]翻译得到的解
    void findCombination(const string &digits, int index, const string &s) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            findCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }

public:
    vector <string> letterCombinations(string digits) {
        if (digits == "") return res;
        findCombination(digits, 0, "");
        return res;
    }
};