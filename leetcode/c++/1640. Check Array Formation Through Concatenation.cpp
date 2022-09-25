// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool canFormArray(vector<int> &arr, vector <vector<int>> &pieces) {
        int n = arr.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[arr[i]] = i;
        }
        int count = 0;
        for (int i = 0; i < pieces.size(); i++) {
            int init = -1;
            for (int x: pieces[i]) {
                if (!record.count(x)) return false;
                if (init == -1) {
                    init = record[x];
                } else {
                    if (init != record[x] - 1) return false;
                    else {
                        init = record[x];
                    }
                }
            }
        }
        return true;
    }
};