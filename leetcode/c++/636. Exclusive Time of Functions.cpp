// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector <string> &logs) {
        vector<int> res(n, 0);
        int m = logs.size();
        stack <pair<int, int>> sk;
        int last = 0;
        for (int i = 0; i < m; i++) {
            string tmp = logs[i];
            istringstream iss(tmp);
            string str;
            getline(iss, str, ':');
            int idx = atoi(str.c_str());
            getline(iss, str, ':');
            if (str == "start") {
                iss >> str;
                int time = atoi(str.c_str());
                if (!sk.empty()) {
                    auto top = sk.top();
                    res[top.first] += time - last;
                }
                sk.push(make_pair(idx, time));
                last = time;
            } else {
                iss >> str;
                int time = atoi(str.c_str());
                auto top = sk.top();
                sk.pop();
                res[top.first] += time - last + 1;
                last = time + 1;
            }
        }
        return res;
    }
};