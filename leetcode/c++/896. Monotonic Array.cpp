// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        int n = A.size();
        if (n <= 2) return true;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] < A[i + 1]) a = 1;
            if (A[i] > A[i + 1]) b = 1;
        }

        if (a + b == 2) {
            return false;
        } else {
            return true;
        }
    }
};