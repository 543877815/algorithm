// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        int i = 30; // 若 "0." 计为两位，i 初始化为 30，若计为 1 位，初始化为 31
        while (num > 0 && i--) {
            num *= 2;
            if (num >= 1) {
                res.push_back('1');
                --num;
            } else res.push_back('0');
        }
        return num != 0 ? "ERROR" : res;
    }
};