// 模拟+有序集合+优先队列
// 时间复杂度：O((k+n)logk)
// 空间复杂度：O(k)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> idle;
        for (int i = 0; i < k; i++) idle.insert(i);
        int m = arrival.size();
        vector<int> cnt(k, 0);
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> _using;
        for (int i = 0; i < m; i++) {
            long start = arrival[i], end = arrival[i] + load[i], id = i % k;
            while (!_using.empty() && _using.top().first <= start) {
                idle.insert(_using.top().second);
                _using.pop();
            }
            if (idle.empty()) {
                continue;
            }
            auto p = idle.lower_bound(id);
            if (p == idle.end()) {
                p = idle.begin();
            }
            _using.emplace(end, *p);
            cnt[*p]++;
            idle.erase(p);

        }
        int max_num = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k ; i++) {
            if (cnt[i] == max_num) {
                res.push_back(i);
            }
        }
        return res;
    }
};