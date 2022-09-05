// 时间复杂度：O(n+m(logn+logm))
// 空间复杂度：O(n)
// 双堆模拟
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [&](auto &a, auto &b) {return a[0] < b[0];});
        vector<int> cnt(n, 0);
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> _using;
        priority_queue<int, vector<int>, greater<>> idle;
        for (int i = 0; i < n; i++) idle.push(i);
        for (int i = 0; i < m; i++) {
            long start = meetings[i][0], end = meetings[i][1], id;
            while (!_using.empty() && _using.top().first <= start) {
                idle.push(_using.top().second); // 维护在start时刻空闲的会议室
                _using.pop();
            }

            if (idle.empty()) {
                auto [e, j] = _using.top(); // 如果没有可用的会议室，那么弹出一个最早结束的会议室
                _using.pop();
                end += e - start;   // 更新当前会议结束的时间
                id = j;
            } else {
                id = idle.top();
                idle.pop();
            }

            cnt[id]++;
            _using.emplace(end, id); // 使用一个会议室
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > cnt[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};