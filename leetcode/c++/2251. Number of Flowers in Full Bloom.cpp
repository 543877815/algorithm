// 差分
// 时间复杂度：O(nlogn+mlogm)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> fullBloomFlowers(vector <vector<int>> &flowers, vector<int> &persons) {
        map<int, int> diff;
        for (auto &f :flowers) {
            ++diff[f[0]];
            --diff[f[1] + 1];
        }

        int n = persons.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) { return persons[i] < persons[j]; });

        vector<int> ans(n);
        auto it = diff.begin();
        int sum = 0;
        for (int i: id) {
            while (it != diff.end() && it->first <= persons[i]) sum += it++->second;
            ans[i] = sum;
        }
        return ans;
    }
};

// 转换+二分
// 时间复杂度：O((n+m)logn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fullBloomFlowers(vector <vector<int>> &flowers, vector<int> &persons) {
        int n = flowers.size(), m = persons.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = (upper_bound(start.begin(), start.end(), persons[i]) - start.begin() -
                      (lower_bound(end.begin(), end.end(), persons[i]) - end.begin()));
        }
        return res;
    }
};