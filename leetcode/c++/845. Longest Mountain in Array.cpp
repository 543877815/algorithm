// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int longestMountain(vector<int> &A) {
        int n = A.size();
        if (n < 3) return 0;
        int left = 0, right = n - 1, res = 0;
        int maxn = 0;
        for (int i = 1; i < n - 1; i++) {
            if (A[i - 1] >= A[i] || A[i + 1] >= A[i]) continue;
            left = i - 1;
            right = i + 1;
            while (right + 1 < n && A[right] > A[right + 1]) right++;
            while (left - 1 >= 0 && A[left] > A[left - 1]) left--;
            maxn = max(maxn, right - left + 1);
        }

        return maxn;
    }
};