// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int length1 = num1.size(), length2 = num2.size(), index1 = 0, index2 = 0;
        int count = 0;
        string res;

        while(index1 < length1 && index2 < length2) {
            int tmp = (num1[index1++] - '0') + (num2[index2++] - '0') + count;
            count = tmp / 10;
            res +=  to_string(tmp % 10);
        }

        while(index1 < length1) {
            int tmp = (num1[index1++] - '0') + count;
            count = tmp / 10;
            res += to_string(tmp % 10);
        }

        while(index2 < length2) {
            int tmp = (num2[index2++] - '0') + count;
            count = tmp / 10;
            res += to_string(tmp % 10);
        }

        if (count) res += to_string(count);

        reverse(res.begin(), res.end());

        return res;

    }
};