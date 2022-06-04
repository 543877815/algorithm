// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */

    bool checkIPV4(string &IP) {
        int n = IP.size();
        bool prefix_zero = false; // 是否含有前导0
        int num_zero = 0;
        int num = 0;

        int num_point = 0;
        for (int i = 0; i < n; i++) {
            if (!isdigit(IP[i]) && IP[i] != '.') return false;  // 存在不合法字符
            if (i == 0 && IP[i] == '.') return false;   // 存在.在字段最前
            if (isdigit(IP[i])) {
                if (prefix_zero && num_zero > 1) return false;  // 存在两个前导0
                if (IP[i] == '0') {
                    num_zero++;
                    if (!prefix_zero && num == 0) prefix_zero = true;  // 前导0
                } else {
                    if (prefix_zero) return false;
                }
                num = num * 10 + (IP[i] - '0');
            } else {
                num_point++;
                if (num > 255) return false;
                num = 0;
                num_zero = 0;
                prefix_zero = false;
            }
        }
        if (prefix_zero && num_zero > 1) return false;  // 存在两个前导0
        if (num > 255) return false;
        if (num_point != 3) return false; // 如果没有3段
        return true;
    }

    bool checkIPV6(string &IP) {
        int n = IP.size();
        int num_chara = 0;
        int num_zero = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (IP[i] == ':') {
                num_chara++;
                if (count > 4 || count == 0) return false;
                if (num_zero == count && num_zero > 1) return false;
                count = 0;
            } else if ((IP[i] > 'f' && IP[i] <= 'z') || IP[i] > 'F' && IP[i] <= 'Z') {
                return false;
            } else {
                count++;
            }
        }
        if (count > 4 || count == 0) return false;
        if (num_zero == count && num_zero > 1) return false;
        if (num_chara != 7) return false;
        return true;
    }

    string solve(string IP) {
        // write code here
        int n = IP.size();
        if (n < 7 || n > 39) return "Neither";
        bool getIPV4 = false;
        bool getIPV6 = false;
        for (int i = 0; i < n; i++) {
            if (IP[i] == '.') getIPV4 = true;
            if (IP[i] == ':') getIPV6 = true;
        }
        if (getIPV4 && getIPV6) return "Neither";

        bool isIPV4 = false;
        if (getIPV4) isIPV4 = checkIPV4(IP);
        if (isIPV4) return "IPv4";

        bool isIPV6 = false;
        if (getIPV6) isIPV6 = checkIPV6(IP);
        if (isIPV6) return "IPv6";
        return "Neither";
    }
};