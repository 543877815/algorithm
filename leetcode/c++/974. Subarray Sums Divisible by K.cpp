// 哈希表+前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int n = nums.size();
        int presum = 0, res = 0;
        unordered_map<int, int> record;
        record[0] = 1;
        for (int i = 0; i < n; i++) {
            presum += nums[i];

            int key = (presum % k + k) % k;  // 防止被除数是负数的情况
            if (record.find(key) != record.end()) {
                res += record[key];
            }

            record[key]++;
        }

        return res;
    }
};

// 时间复杂度：O(logn)
// 空间复杂度：O(n)
class Solution {
public:
    void search(vector<int> &arr, int left, int right, int &res) {
        int middle = left + (right - left) / 2;
        if (left <= right) {
            if (arr[middle] > arr[middle+1] && arr[middle] > arr[middle-1] ) {
                res = middle;
            } else {
                search(arr, left, middle - 1, res);
                search(arr, middle + 1, right, res);
            }
        }
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 1, right = n - 2;
        int res = 0;
        search(arr, left, right, res);
        return res;
    }
};

// 二分查找非递归
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 1, right = n - 2, res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1]) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

