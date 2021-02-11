// 双指针、哈希表、滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int atMostKDistanct(vector<int> &A, int K) {
        int n = A.size();
        int res = 0;
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> record;
        while (right < n) {
            if (record[A[right]] == 0) count++;
            record[A[right]]++;
            right++;
            while (count > K) {
                record[A[left]]--;
                if (record[A[left]] == 0) count--;
                left++;
            }
            res += right - left;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int> &A, int K) {
        // 「最多存在 K 个不同整数的子区间的个数」与 「最多存在 K - 1 个不同整数的子区间的个数」的差
        return atMostKDistanct(A, K) - atMostKDistanct(A, K - 1);
    }
};