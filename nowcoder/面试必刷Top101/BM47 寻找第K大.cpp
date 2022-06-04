class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        sort(a.begin(), a.end(), greater<int>());
        return a[K - 1];
    }
};


// 二分中断、牛客网测试超时
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int partion(vector<int> &a, int left, int right) {
        int i = left, j = right;
        int base = a[left];
        while (i < j) {
            while (i < j && a[j] <= base) {
                j--;
            }

            while (i < j && a[i] >= base) {
                i++;
            }
            if (i < j) swap(a[i], a[j]);
        }

        a[left] = a[i];
        a[i] = base;

        return i;
    }

    int quickSort(vector<int>&a, int left, int right, int K) {
        int p = partion(a, left, right);
        int pos = p - left + 1;
        if (K == pos) return a[p];
        else if (K < pos) return quickSort(a, left, p-1, K);
        else return quickSort(a, p+1, right, K - pos);
    }

    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quickSort(a, 0, n-1, K);
    }
};