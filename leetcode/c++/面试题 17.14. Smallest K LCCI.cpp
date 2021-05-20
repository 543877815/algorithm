// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        vector<int> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
};

// 优先队列
// 时间复杂度：O(nlonk)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        vector<int> res;
        int n = arr.size();
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        res.resize(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }

        return res;
    }
};