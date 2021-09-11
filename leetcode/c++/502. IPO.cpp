// 利用堆的贪心算法
// 时间复杂度：O((n+k)logn)
// 空间复杂度：O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector <pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({capital[i], profits[i]}); // 根据最小资本排序
        }
        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; i++) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else break;
        }

        return w;
    }
};