// 快速排序+贪心
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = 0;
        if (arr[0] != 1) arr[0] = 1;
        int maxn = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maxn = max(maxn, arr[i]);
        }
        return maxn;
    }
};

// 计数排序
// 空间复杂度：O(n)
// 时间复杂度：O(n)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> record = vector(n+1, 0);
        for (int i = 0; i < n; i++) {
            if (arr[i] > n) {
                record[n]++;
            } else {
                record[arr[i]]++;
            }
        }
        int miss = 0;
        for (int i = 1; i <= n; i++) {
            if (record[i] == 0) miss++;
            else miss -= min(record[i] - 1, miss);
        }

        return n - miss;
    }
};