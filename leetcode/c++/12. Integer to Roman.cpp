
// 时间复杂度：O(1)
// 空间复杂度：O(1)
char *intToRoman(int num) {
    static char str[17];
    int size = 0;
    char romanChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int index = 0;
    while (num != 0) {
        int carry = num % 10;
        while (true) {
            if (carry == 9) {
                str[size++] = romanChar[index + 2];
                carry = 1;
            }
            if (carry == 8) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 7) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 6) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 5) {
                str[size++] = romanChar[index + 1];
                break;
            }
            if (carry == 4) {
                str[size++] = romanChar[index + 1];
                carry = 1;
            }
            if (carry == 3) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 2) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 1) {
                str[size++] = romanChar[index];
                break;
            }
            if (carry == 0) {
                break;
            }
        }
        index += 2;
        num /= 10;
    }

    for (int i = 0; i < size / 2; i++) {
        char tmp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = tmp;
    }
    str[size] = 0;
    return str;
}


// 模拟
// 时间复杂度：O(1)
// 空间复杂度：O(1)
const pair<int, string> value2symbols[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}
};

class Solution {
public:
    string intToRoman(int num) {
        string res;
        for (const auto &[key, value] : value2symbols) {
            while (num >= key) {
                num -= key;
                res += value;
            }
            if (num == 0) break;
        }

        return res;
    }
};

// 编码
// 时间复杂度：O(1)
// 空间复杂度：O(1)
const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

