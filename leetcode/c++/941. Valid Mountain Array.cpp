// 线性扫描
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() <= 2) return false;
        int up = -1;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i + 1]) return false;
            if (up == -1) {
                if (A[i] > A[i + 1]) up = i;
            } else {
                if (A[i] < A[i + 1]) return false;
            }
        }
        return up > 0;
    }
};