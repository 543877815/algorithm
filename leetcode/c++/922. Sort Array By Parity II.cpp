// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 双指针
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int j = n - 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while (j > 1 && A[j] % 2 == 1) j -= 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};