// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
        }

        return -1;
    }
};

// 二分搜索
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        int left = 1, right = n - 2, res = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] > arr[middle + 1]) {
                res = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return res;
    }
};