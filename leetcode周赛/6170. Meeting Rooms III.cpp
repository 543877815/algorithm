// ʱ�临�Ӷȣ�O(n+m(logn+logm))
// �ռ临�Ӷȣ�O(n)
// ˫��ģ��
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
                idle.push(_using.top().second); // ά����startʱ�̿��еĻ�����
                _using.pop();
            }

            if (idle.empty()) {
                auto [e, j] = _using.top(); // ���û�п��õĻ����ң���ô����һ����������Ļ�����
                _using.pop();
                end += e - start;   // ���µ�ǰ���������ʱ��
                id = j;
            } else {
                id = idle.top();
                idle.pop();
            }

            cnt[id]++;
            _using.emplace(end, id); // ʹ��һ��������
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