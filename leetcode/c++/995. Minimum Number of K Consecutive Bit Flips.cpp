// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i >= K && A[i - K] > 1) {
                cnt ^= 1;
                A[i - K] -= 2;
            }
            if (A[i] == cnt) {
                if (i + K > n) return -1;
                ans++;
                cnt ^= 1;
                A[i] += 2;
            }
        }

        return ans;
    }
};