// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (n - i <= citations[i])
                res = max(res, n - i);
            else break;
        }

        return res;
    }
};


// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int middle = (right - left) / 2 + left;
            if (citations[middle] >= n - middle) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return n - left;
    }
};