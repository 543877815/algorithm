// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    string maximumTime(string time) {
        string res;

        // res[0]
        if (time[0] == '?') {
            if (time[1] <= '3' || time[1] == '?') {
                res.push_back('2');
            } else {
                res.push_back('1');
            }
        } else {
            res.push_back(time[0]);
        }

        // res[1]
        if (time[1] == '?') {
            if (res[0] == '2') {
                res.push_back('3');
            } else {
                res.push_back('9');
            }
        } else {
            res.push_back(time[1]);
        }

        res.push_back(':');

        // res[3]
        if (time[3] == '?') {
            res.push_back('5');
        } else {
            res.push_back(time[3]);
        }

        // res[4]
        if (time[4] == '?') {
            res.push_back('9');
        } else {
            res.push_back(time[4]);
        }

        return res;
    }
};