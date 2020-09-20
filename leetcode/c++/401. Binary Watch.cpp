// 回溯
class Solution {
private:
    vector<int> list;
    vector <string> res;
public:
    void DFS(int num, int count, int curr, int h_sum, int m_sum) {
        if (h_sum < 0 || h_sum > 11 || m_sum > 59 || m_sum < 0) return;
        if (num == count) {
            string m_str = to_string(m_sum);
            string h_str = to_string(h_sum);
            string tmp;
            if (m_str.size() == 1) {
                tmp = h_str + ":0" + m_str;
            } else {
                tmp = h_str + ":" + m_str;
            }
            res.push_back(tmp);
            return;
        }

        for (int i = curr; i < list.size(); i++) {
            if (i < 6) m_sum += list[i];
            else h_sum += list[i];
            DFS(num, count + 1, i + 1, h_sum, m_sum);
            if (i < 6) m_sum -= list[i];
            else h_sum -= list[i];
        }
    }

    vector <string> readBinaryWatch(int num) {
        list = {1, 2, 4, 8, 16, 32, 1, 2, 4, 8};
        vector <string> t;
        DFS(num, 0, 0, 0, 0);
        return res;
    }
};