// 时间复杂度：log(n)
// 空间复杂度：log(n)
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int pre = 1, curr = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '5')) curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};