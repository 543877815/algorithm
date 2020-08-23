// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        if (K == 0) return A;
        vector<int> B;
        while (K > 0) {
            int num = K % 10;
            B.insert(B.begin(), num);
            K /= 10;
        }
        int m = A.size();
        if (m == 0) return B;
        int n = B.size();
        int i = m - 1, j = n - 1, count = 0;
        while (i >= 0 && j >= 0) {
            int sum = A[i] + B[j] + count;
            A[i] = sum % 10;
            count = sum / 10;
            i--;
            j--;
        }

        while (i >= 0) {
            int sum = A[i] + count;
            A[i] = sum % 10;
            count = sum / 10;
            i--;
        }

        while (j >= 0) {
            int sum = B[j] + count;
            A.insert(A.begin(), sum % 10);
            count = sum / 10;
            j--;
        }

        if (count != 0) A.insert(A.begin(), count);

        return A;
    }
};