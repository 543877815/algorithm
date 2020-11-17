// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int m = people.size();
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(2));
        sort(people.begin(), people.end(), [&](vector<int> &x, vector<int> &y) {
            if (x[0] != y[0]) return x[0] < y[0];
            else return x[1] > y[1];
        });

        vector<bool> used = vector<bool>(m, false);
        for (int i = 0; i < m; i++) {
            int idx = people[i][1];
            int j = 0;
            while ((idx > 0 && j < m) || used[j]) {
                if (!used[j]) {
                    idx--;
                }
                j++;
            }
            if (j < m) {
                used[j] = true;
                res[j] = people[i];
            }
        }
        return res;
    }
};