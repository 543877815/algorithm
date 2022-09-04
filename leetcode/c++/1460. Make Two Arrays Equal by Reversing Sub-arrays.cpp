// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        int n = target.size();
        int m = arr.size();
        if (n != m) return false;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (target[i] != arr[i]) return false;
        }

        return true;
    }
};