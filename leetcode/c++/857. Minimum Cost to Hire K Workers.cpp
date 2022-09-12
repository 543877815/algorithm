// 贪心+大顶堆
// 时间复杂度：O(nlogn+nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size();
        vector<int> id(n);
        int total_q = 0;
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return wage[i] * quality[j] < wage[j] * quality[i];  // 按照wage[i]/quality[i]从小到大排序
        });
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(quality[id[i]]);
            total_q += quality[id[i]];
        }
        double res = total_q * ((double) wage[id[k - 1]] / quality[id[k - 1]]); // 选 r 值最小的 k 名工人组成当前的最优解
        for (int i = k; i < n; i++) {
            if (int q = quality[id[i]]; q < pq.top()) {
                total_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                res = min(res, total_q * ((double) wage[id[i]] / q));
            }
        }
        return res;
    }
};