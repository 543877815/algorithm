// 贪心算法
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int R_num = 0, D_num = 0;
        for (int i = 0; i < n; i++) {p
            if (senate[i] == 'R') R_num++;
            if (senate[i] == 'D') D_num++;
        }
        vector<bool> mark(n, true);
        // 多次循环
        while (D_num > 0 && R_num > 0) {
            for (int i = 0; i < n; i++) {
                // 跳过
                if (mark[i] == false) continue;
                int j = i;
                if (senate[i] == 'D') {
                    while (R_num > 0) {
                        j++;
                        if (j == n) j = 0;
                        if (senate[j] == 'R' && mark[j]) {
                            mark[j] = false;
                            R_num--;
                            break;
                        }
                    }
                } else if (senate[i] == 'R') {
                    while (D_num > 0) {
                        j++;
                        if (j == n) j = 0;
                        if (senate[j] == 'D' && mark[j]) {
                            mark[j] = false;
                            D_num--;
                            break;
                        }
                    }
                }
                if (D_num == 0 || R_num == 0) break;
            }
        }
        cout << R_num << " " << D_num;
        return R_num == 0 ? "Dire" : "Radiant";
    }
};


/*
 * "DRRDRDRDRDDRDRDR"
 *      40
 * 48   38
 * 32   36
 * 30   24
 * 28   22
 * 26   20
 * 16   18
 * 14   15
 * 12   13
 * 10   11
 * 9    8
 * 7    6
 * 5    4
 * 3    2
 * 0    1
 */

// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                radiant.push(radiant.front() + n);
            } else {
                dire.push(dire.front() + n);
            }
            radiant.pop();
            dire.pop();
        }
        return !radiant.empty() ? "Radiant" : "Dire";
    }
};