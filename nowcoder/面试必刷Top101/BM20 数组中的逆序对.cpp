// 归并排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    const int MOD = 1000000007;

    void merge(vector<int>&data, vector<int>&tmp, int left, int right, int &res) {
        int idx = 0;
        int middle = (right - left) / 2 + left;
        int i = left, j = middle + 1;
        while (i <= middle && j <= right) {
            if (data[i] > data[j]) {
                tmp[idx++] = data[j++];
                res += (middle - i + 1);
                res %= MOD;
            } else {
                tmp[idx++] = data[i++];
            }
        }

        while (i <= middle) {
            tmp[idx++] = data[i++];
        }

        while (j <= right) {
            tmp[idx++] = data[j++];
        }

        for (int i = left, k=0; i <= right; i++, k++) {
            data[i] = tmp[k];
        }
    }

    void sort(vector<int> &data, vector<int>& tmp, int left, int right, int &res) {
        if (left >= right) return;
        int middle = (right - left) / 2 + left;
        sort(data, tmp, left, middle, res);
        sort(data, tmp, middle + 1, right, res);
        merge(data, tmp, left, right, res);
    }

    int InversePairs(vector<int> data) {
        int n = data.size();
        int res = 0;
        if (n == 0) return res;
        vector<int> tmp(n);

        sort(data, tmp, 0, n-1, res);
        return res;
    }
};