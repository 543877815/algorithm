// 回溯 DFS
// 时间复杂度 : 如上文所述，需要检查的组合不多于27个。
// 空间复杂度 : 常数空间存储解，不多于19 个有效IP地址。
class Solution {
private:
    vector<string> res;
public:
    void getIP(const string &s, int index, int pointNum) {
        int num = 0;
        if (pointNum == 3 && s[s.size() - 1] != '.') {  // 如果以.结尾则不合法
            if (s[index] == '0' && index != s.size() - 1) return; // 如果最后存在.0xx则不合法
            while (index < s.size()) {
                num = num * 10 + (s[index++] - '0');
                if (num > 255) return;  // 如果最后存在.256则不合法
            }
            res.push_back(s);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (index + i == s.size()) return;
            num = num * 10 + (s[index + i] - '0');
            if (num >= 0 && num <= 255) {
                getIP(s.substr(0, index + i + 1) + "." + s.substr(index + i + 1), index + i + 2, pointNum + 1); // 分别为后面1,2,3个数字进行截断
                if (s[index] == '0') break; // 如果以 0 开头则后面不可取
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return res;
        getIP(s, 0, 0);
        int a = 0;
        return res;
    }
};