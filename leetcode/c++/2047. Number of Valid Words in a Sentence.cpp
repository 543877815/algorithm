// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int hyphen; // 连字符
    int mark;   // 标点符号
    int digit;  // 数字
    int letter; // 小写字母
    int begin;

    void reset(int i) {
        hyphen = 0;
        mark = 0;
        digit = 0;
        letter = 0;
        begin = i;
    }

    int countValidWords(string sentence) {
        sentence += ' ';
        int n = sentence.size();
        int i = 0;
        reset(0);
        int res = 0;
        while (i < n) {
            char a = sentence[i];
            if (sentence[i] == ' ') {
                if ((hyphen <= 1) && (mark <= 1) && (digit == 0) && letter > 0 && sentence[begin] != '-' &&
                    (i > 0 && sentence[i - 1] != '-')) {
                    res++;
                }
                reset(i + 1);
            } else if (sentence[i] == '-') {
                hyphen++;
            } else if (isdigit(sentence[i])) {
                digit++;
            } else if (islower(sentence[i])) {
                letter++;
            } else if (sentence[i] == '!' || sentence[i] == ',' || sentence[i] == '.') {
                mark++;
                if (sentence[i + 1] != ' ') {
                    while (i < n && sentence[i] != ' ')i++;
                } else {
                    if ((hyphen <= 1) && (mark <= 1) && (digit == 0) && letter >= 0 && sentence[begin] != '-') {
                        if (i > 0 && sentence[i - 1] == '-') continue;
                        res++;
                    }
                }
                reset(i + 1);
            }
            i++;
        }
        return res;
    }
};
