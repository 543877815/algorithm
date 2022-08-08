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

// 2022.08.05
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])  return a[0] > b[0];
            else return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            pq.push(people[i]);
        }

        vector<bool> visited(n, false);
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (!visited[i] || people[i][0] >= top[0]) count++;
                if (count == top[1] + 1) {
                    visited[i] = true;
                    people[i] = top;
                    break;
                }
            }
        }

        return people;
    }
};