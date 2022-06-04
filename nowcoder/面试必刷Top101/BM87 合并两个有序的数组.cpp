// 双指针
// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int index = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[index--] = A[i--];
            } else {
                A[index--] = B[j--];
            }
        }
        while (i >= 0) {
            A[index--] = A[i--];
        }

        while (j >= 0) {
            A[index--] = B[j--];
        }
    }
};