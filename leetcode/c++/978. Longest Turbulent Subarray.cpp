// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int> &A) {
        int n = A.size();
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            if (A[i + 1] > A[i]) A[i] = -1;
            else if (A[i + 1] == A[i]) A[i] = 0;
            else A[i] = 1;
        }

        int left = -1, right = 0;
        while (right < n - 1) {
            if (A[right] * A[right + 1] != -1) {
                if (A[right] != 0) res = max(res, right - left + 1);
                left = right;
            }
            right++;
        }

        return res;
    }
};