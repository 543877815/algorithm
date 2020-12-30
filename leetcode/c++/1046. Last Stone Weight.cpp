// 优先队列
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while(!pq.empty()) {
            int a = pq.top(); pq.pop();
            if (pq.empty()) return a;
            int b = pq.top(); pq.pop();
            int dis = abs(a-b);
            if (dis != 0) pq.push(dis);
        }

        return 0;
    }
};