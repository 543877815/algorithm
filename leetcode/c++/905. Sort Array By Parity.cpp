// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int j = n - 1;
        for (int i = 0; i < n, i < j; i++) {
            if (A[i] % 2 == 1) {
                while (j > i && A[j] % 2 == 1) j--;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};