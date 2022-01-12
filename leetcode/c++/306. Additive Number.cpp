// 确定第一个和第二个数的位置，模拟
// 时间复杂度：O(n^3)
// 空间复杂度：O(n)
class Solution {
public:
    string stringAdd(string &num, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) cur += num[firstEnd--] - '0';
            if (secondEnd >= secondStart) cur += num[secondEnd--] - '0';
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }

        reverse(third.begin(), third.end());
        return third;
    }

    bool valid(string &num, int secondStart, int secondEnd) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondStart <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) break;
            if (thirdEnd == n - 1) return true;
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; secondStart++) {
            if (num[0] == '0' && secondStart != 1) break;
            for (int secondEnd = secondStart; secondEnd < n - 1; secondEnd++) {
                if (num[secondStart] == '0' && secondStart != secondEnd) break;
                if (valid(num, secondStart, secondEnd)) return true;
            }
        }
        return false;
    }
};