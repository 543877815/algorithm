// 前缀和
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<int> presum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + arr[i];
        }
        int sum = 0;
        int obb = 1;
        while (obb <= n) {
            int index = obb;
            while (index <= n) {
                sum += presum[index] - presum[index - obb];
                index++;
            }
            obb += 2;
        }
        return sum;
    }
};

// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - i;
            int leftEven = (left + 1) / 2, rightEven = (right + 1) / 2;
            int leftObb = left / 2, rightObb = right / 2;
            res += (leftEven * rightEven + leftObb * rightObb) * arr[i];
        }

        return res;
    }
};