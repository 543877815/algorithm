// 大顶堆
// 时间复杂度：O(nlogk)
// 空间复杂度：O(k)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>res(k,0);
        if (k==0) return res;

        priority_queue<int>Q;
        for (int i = 0; i < k; i++) Q.push(arr[i]);
        for (int i = k; i < arr.size(); i++) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            res[i] = Q.top();
            Q.pop();
        }
        return res;
    }
};