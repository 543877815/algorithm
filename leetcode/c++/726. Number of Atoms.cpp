// 栈 + 哈希表
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.size();
        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i])) {
                atom += formula[i++];
            }
            return atom;
        };

        auto parseNum = [&]() -> int {
            int num = 0;
            if (i == n || !isdigit(formula[i])) {
                return 1;
            }
            while (i < n && isdigit(formula[i])) {
                num = num * 10 + int(formula[i++] - '0');
            }
            return num;
        };

        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n) {
            if (formula[i] == '(') {
                i++;
                stk.push({});
            } else if (formula[i] == ')') {
                i++;
                int num = parseNum();
                auto atomNum = stk.top();
                stk.pop();
                for (auto & [atom, v] : atomNum) {
                    stk.top()[atom] += v * num;
                }
            } else {
                string atom = parseAtom();
                int num = parseNum();
                stk.top()[atom] += num;
            }
        }

        auto atomNum = stk.top();

        vector<pair<string, int>> pairs;
        for (auto & [atom, v]: atomNum) {
            pairs.emplace_back(atom, v);
        }

        sort(pairs.begin(), pairs.end());

        string res;
        for (auto & p: pairs) {
            res += p.first;
            if (p.second > 1) {
                res += to_string(p.second);
            }
        }

        return res;
    }
};