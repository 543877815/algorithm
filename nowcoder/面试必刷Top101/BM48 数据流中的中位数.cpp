// 大小顶堆
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    priority_queue<double, vector<double>, greater<double>> pq1; // 小顶堆 放大数据
    priority_queue<double, vector<double>, less<double>> pq2; // 大顶堆 放小数据

    void Insert(int num) {
        if (pq1.empty()) pq1.push(num);
        else {
            if (num > pq1.top()) {
                pq1.push(num);
            } else {
                pq2.push(num);
            }
        }
        int size1 = pq1.size(), size2 = pq2.size();
        if (size1 - size2 >= 2) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if (size2 - size1 >= 2) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double GetMedian() {
        int size1 = pq1.size(), size2 = pq2.size();
        if ((size1 + size2) % 2 == 1) {
            if (size1 > size2) return pq1.top();
            else return pq2.top();
        } else {
            return (pq1.top() + pq2.top()) / 2;
        }
    }
};