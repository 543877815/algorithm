// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
// 归并排序
class Solution {
public:
    vector<int> res;

    void sort(vector <pair<int, int>> &arr, int left, int right) {
        if (left == right) return;
        int mid = left + (right - left) / 2;
        this->sort(arr, left, mid);
        this->sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector <pair<int, int>> tmp;

    void merge(vector <pair<int, int>> &arr, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp[i] = arr[i];
        }

        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                arr[k] = tmp[j++];
            } else if (j == right + 1) {
                arr[k] = tmp[i++];
                res[arr[k].second] += j - mid - 1;
            } else if (tmp[i].first > tmp[j].first) {
                arr[k] = tmp[j++];
            } else {
                arr[k] = tmp[i++];
                res[arr[k].second] += j - mid - 1;
            }
        }
    }

    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector <pair<int, int>> arr(n);
        tmp = vector < pair < int, int >> (n);
        res = vector<int>(n);
        for (int i = 0; i < n; i++) {
            arr[i] = make_pair(nums[i], i);
        }
        this->sort(arr, 0, n - 1);
        return res;
    }
};