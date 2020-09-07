// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int index = A.size() - 1;
        n--;
        m--;
        while (m >= 0 && n >= 0) {
            A[index--] = A[m] > B[n] ? A[m--] : B[n--];
        }

        while (m >= 0) {
            A[index--] = A[m--];
        }

        while (n >= 0) {
            A[index--] = B[n--];
        }

    }
};
