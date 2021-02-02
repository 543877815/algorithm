// 双指针 滑动窗口
// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int n = A.size();
        vector<int> num(2);
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[A[right]]++;
            maxn = max(maxn, num[1]);
            if (right - left + 1 - maxn > K) {
                num[A[left]]--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};