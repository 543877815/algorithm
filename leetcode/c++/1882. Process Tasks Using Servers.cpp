// 双堆模拟
// 时间复杂度：O(n+m)log
// 空间复杂度：O(n)
class Solution {
public:
    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle;  // [weight, idx]
        for (int i = 0; i < n; i++)  idle.emplace(servers[i], i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> _using;  // [end, idx]

        vector<int> res(m, 0);
        long long ts = 0;

        auto release = [&]() {
            while (!_using.empty() && _using.top().first <= ts) {
                auto &&[_, idx] = _using.top();
                idle.emplace(servers[idx], idx );
                _using.pop();
            }
        };

        for (int i = 0; i < m; i++) {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty()) {
                ts = _using.top().first;
                release();
            }
            auto &&[_, idx] = idle.top();
            _using.emplace(ts+tasks[i], idx);
            res[i] = idx;
            idle.pop();
        }

        return res;
    }
};