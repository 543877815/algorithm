// 优先队列
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res(m);
        if (n == 0 || m == 0) return res;
        int p = nums[0].size();
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b)
        { return a.first != b.first ? a.first > b.first : a.second > b.second; };


        for (int i = 0; i < m; i++) {

            int k = queries[i][0], trim = queries[i][1];

            priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

            for (int j = 0; j < n; j++) {
                string num = nums[j].substr(p - trim);
                pq.push(make_pair(num, j));
            }

            while (k > 1) {
                pq.pop();
                k--;
            }
            res[i] = pq.top().second;
        }
        return res;
    }
};