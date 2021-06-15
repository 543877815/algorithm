// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return 0;
    }
};