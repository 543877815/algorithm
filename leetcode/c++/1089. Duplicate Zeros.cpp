// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                for (int j = n - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                if (i < n - 1) arr[i + 1] = 0;
                i++;
            }
        }
    }
};
