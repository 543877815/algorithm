// ̰��+�󶥶�
// ʱ�临�Ӷȣ�O(nlogn+nlogk)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size();
        vector<int> id(n);
        int total_q = 0;
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return wage[i] * quality[j] < wage[j] * quality[i];  // ����wage[i]/quality[i]��С��������
        });
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(quality[id[i]]);
            total_q += quality[id[i]];
        }
        double res = total_q * ((double) wage[id[k - 1]] / quality[id[k - 1]]); // ѡ r ֵ��С�� k ��������ɵ�ǰ�����Ž�
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