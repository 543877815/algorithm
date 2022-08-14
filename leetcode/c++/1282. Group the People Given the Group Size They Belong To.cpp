// ����
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(logn)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return groupSizes[i] < groupSizes[j];
        });
        vector<vector<int>> res;

        int last = groupSizes[id[0]];
        vector<int> tmp = {id[0]};
        for (int i = 1; i < n; i++) {
            if (groupSizes[id[i]] != last || tmp.size() == last) {
                last = groupSizes[id[i]];
                res.push_back(tmp);
                tmp.clear();
                tmp.push_back(id[i]);
            } else {
                tmp.push_back(id[i]);
            }
        }

        if (!tmp.empty()) res.push_back(tmp);
        return res;
    }
};