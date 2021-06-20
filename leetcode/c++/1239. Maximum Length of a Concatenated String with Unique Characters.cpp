// 回溯+位运算
// 时间复杂度：O(sigma+2^n)
// 空间复杂度：O(n)
class Solution {
public:
    void backward(vector<int> &record, int index, int mask, int &res) {
        if (index == record.size()) {
            res = max(res, __builtin_popcount(mask));
            return;
        }
        if ((mask & record[index]) == 0) {
            backward(record, index + 1, mask | record[index], res);
        }
        backward(record, index + 1, mask, res);
    }

    int maxLength(vector <string> &arr) {
        int n = arr.size();
        vector<int> record;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < arr[i].size(); j++) {
                int index = arr[i][j] - 'a';
                if ((mask >> index) & 1) {
                    mask = 0;
                    break;
                }
                mask |= (1 << index);
            }
            if (mask != 0) record.push_back(mask);
        }
        int res = 0;
        backward(record, 0, 0, res);
        return res;
    }
};