// 队列
// 时间复杂度：O(1)
// 空间复杂度：O(n)
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() + 3000 < t) {
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */