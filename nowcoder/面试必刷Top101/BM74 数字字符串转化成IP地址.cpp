// »ØËÝ
// Ê±¼ä¸´ÔÓ¶È£ºO(n!)
// ¿Õ¼ä¸´ÔÓ¶È£ºo(n!)
class Solution {
public:
    /**
     *
     * @param s string×Ö·û´®
     * @return string×Ö·û´®vector
     */
    bool isLegal(string &s, int start, int end) {
        if (end - start + 1 >= 4) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = num * 10 + (s[i] - '0');
        }
        if (s[start] == '0' && num > 0) return false;
        if (num == 0 && end - start + 1 >= 2) return false;
        if (num >= 0 && num <= 255) return true;
        else return false;
    }

    vector <string> res;

    void backtrack(string &s, string &tmp, int idx, int point) {
        int n = s.size();
        if (point == 4) {
            if (idx == n) {
                res.push_back(tmp);
            }
            return;
        }
        if (idx != 0) tmp += ".";
        int i = 0;
        while (i < 3 && idx + i < n) {
            if (isLegal(s, idx, idx + i)) {
                tmp += s.substr(idx, i + 1);
                backtrack(s, tmp, idx + i + 1, point + 1);
                tmp.erase(tmp.size() - (i + 1));
                i++;
            } else break;
        }
        if (idx != 0) tmp.pop_back();
    }

    vector <string> restoreIpAddresses(string s) {
        // write code here
        string tmp = "";
        backtrack(s, tmp, 0, 0);
        return res;
    }
};


class Solution {
public:
    /**
     *
     * @param s string×Ö·û´®
     * @return string×Ö·û´®vector
     */
    vector<string> res;

    bool isValid(string &s) {
        if ((s.size() > 1 && s[0] == '0') || s.size() > 3)
            return false;
        return stoi(s) < 256;
    }

    void backtrack(string &s, vector<string> curr, int idx) {
        int n = s.size();
        if (curr.size() == 4) {
            if (n == idx) res.push_back(curr[0] + "." + curr[1] + "." + curr[2] + "." + curr[3]);
            return;
        }

        int i = 1;
        while (i <= 3 && idx + i - 1 < n) {
            string temp = s.substr(idx, i);
            if (isValid(temp)) {
                curr.push_back(temp);
                backtrack(s, curr, idx + i);
                curr.pop_back();

                i++;
            } else break;
        }

    }

    vector<string> restoreIpAddresses(string s) {
        // write code here
        vector<string> curr;
        backtrack(s, curr, 0);
        return res;
    }
};